#include "pch.h"
#include "Tile_Map1.h"
#include "misc/Cgdi.h"
#include "Graph/HandyGraphFunctions.h"
#include "Game/EntityManager.h"
#include "constants.h"
#include "lua/Raven_Scriptor.h"
#include "misc/WindowUtils.h"
#include "objectname.h"
//uncomment to write object creation/deletion to debug console
#define  LOG_CREATIONAL_STUFF

#include "Debug/DebugConsole.h"


//----------------------------- ctor ------------------------------------------
//-----------------------------------------------------------------------------
Tile_Map1::Tile_Map1() :m_pNavGraph(NULL),
m_pSpacePartition(NULL),
m_iSizeY(0),
m_iSizeX(0),
m_dCellSpaceNeighborhoodRange(0)
{
}
//------------------------------ dtor -----------------------------------------
//-----------------------------------------------------------------------------
Tile_Map1::~Tile_Map1()
{
    Clear();
}


//---------------------------- Clear ------------------------------------------
//
//  deletes all the current objects ready for a map load
//-----------------------------------------------------------------------------
void Tile_Map1::Clear()
{
    std::vector<Wall2D*>::iterator curWall = m_Walls.begin();
    for (curWall; curWall != m_Walls.end(); ++curWall)
    {
        delete* curWall;
    }

    m_Walls.clear();
    m_SpawnPoints.clear();

    //delete the navgraph
    delete m_pNavGraph;

    //delete the partioning info
    delete m_pSpacePartition;
}


//----------------------------- AddWall ---------------------------------------
//-----------------------------------------------------------------------------
void Tile_Map1::AddWall(std::ifstream& in)
{
    m_Walls.push_back(new Wall2D(in));
}

Wall2D* Tile_Map1::AddWall(Vector2D from, Vector2D to)
{
    Wall2D* w = new Wall2D(from, to);

    m_Walls.push_back(w);

    return w;
}




//---------------------------- AddSpawnPoint ----------------------------------
//-----------------------------------------------------------------------------
void Tile_Map1::AddSpawnPoint(std::ifstream& in)
{
    double x, y, dummy;

    in >> dummy >> x >> y >> dummy >> dummy;                   //dummy values are artifacts from the map editor

    m_SpawnPoints.push_back(Vector2D(x, y));
}

//------------------------- LoadMap ------------------------------------
//
//  sets up the game environment from map file
//-----------------------------------------------------------------------------
bool Tile_Map1::LoadMap(const std::string& filename)
{
    std::ifstream in(filename.c_str());
    if (!in)
    {
        ErrorBox("Bad Map Filename");
        return false;
    }

    Clear();

    //BaseGameEntity::ResetNextValidID();

    //first of all read and create the navgraph. This must be done before
    //the entities are read from the map file because many of the entities
    //will be linked to a graph node (the graph node will own a pointer
    //to an instance of the entity)
    m_pNavGraph = new NavGraph(false);

    m_pNavGraph->Load(in);

#ifdef LOG_CREATIONAL_STUFF
    debug_con << "NavGraph for " << filename << " loaded okay" << "";
#endif

    //determine the average distance between graph nodes so that we can
    //partition them efficiently
    m_dCellSpaceNeighborhoodRange = CalculateAverageGraphEdgeLength(*m_pNavGraph) + 1;

#ifdef LOG_CREATIONAL_STUFF
    debug_con << "Average edge length is " << CalculateAverageGraphEdgeLength(*m_pNavGraph) << "";
#endif

#ifdef LOG_CREATIONAL_STUFF
    debug_con << "Neighborhood range set to " << m_dCellSpaceNeighborhoodRange << "";
#endif


    //load in the map size and adjust the client window accordingly
    in >> m_iSizeX >> m_iSizeY;

#ifdef LOG_CREATIONAL_STUFF
    debug_con << "Partitioning navgraph nodes..." << "";
#endif

    //partition the graph nodes
    PartitionNavGraph();


    //get the handle to the game window and resize the client area to accommodate
    //the map
    extern char* g_szApplicationName;
    extern char* g_szWindowClassName;
    HWND hwnd = FindWindowA(g_szWindowClassName, g_szApplicationName);
    const int ExtraHeightRqdToDisplayInfo = 50;
    ResizeWindow(hwnd, m_iSizeX, m_iSizeY + ExtraHeightRqdToDisplayInfo);

#ifdef LOG_CREATIONAL_STUFF
    debug_con << "Loading map..." << "";
#endif


    //now create the environment entities
    while (!in.eof())
    {
        //get type of next map object
        int EntityType;

        in >> EntityType;

#ifdef LOG_CREATIONAL_STUFF
        debug_con << "Creating a " << GetNameOfType(EntityType) << "";
#endif

        //create the object
        switch (EntityType)
        {
        case type_wall:

            AddWall(in); break;

        case type_spawn_point:

            AddSpawnPoint(in); break;

        default:

            throw std::runtime_error("<Map::Load>: Attempting to load undefined object");

            return false;

        }//end switch
    }

#ifdef LOG_CREATIONAL_STUFF
    debug_con << filename << " loaded okay" << "";
#endif

    //calculate the cost lookup table
    m_PathCosts = CreateAllPairsCostsTable(*m_pNavGraph);

    return true;
}





//------------- CalculateCostToTravelBetweenNodes -----------------------------
//
//  Uses the pre-calculated lookup table to determine the cost of traveling
//  from nd1 to nd2
//-----------------------------------------------------------------------------
double
Tile_Map1::CalculateCostToTravelBetweenNodes(int nd1, int nd2)const
{
    assert(nd1 >= 0 && nd1 < m_pNavGraph->NumNodes() &&
        nd2 >= 0 && nd2 < m_pNavGraph->NumNodes() &&
        "<Raven_Map::CostBetweenNodes>: invalid index");

    return m_PathCosts[nd1][nd2];
}




//-------------------------- PartitionEnvironment -----------------------------
//-----------------------------------------------------------------------------
void Tile_Map1::PartitionNavGraph()
{
    if (m_pSpacePartition) delete m_pSpacePartition;

    m_pSpacePartition = new CellSpacePartition<NavGraph::NodeType*>(m_iSizeX,
        m_iSizeY,
        script->GetInt("NumCellsX"),
        script->GetInt("NumCellsY"),
        m_pNavGraph->NumNodes());

    //add the graph nodes to the space partition
    NavGraph::NodeIterator NodeItr(*m_pNavGraph);
    for (NavGraph::NodeType* pN = NodeItr.begin();!NodeItr.end();pN = NodeItr.next())
    {
        m_pSpacePartition->AddEntity(pN);
    }
}

//------------------------- GetRandomNodeLocation -----------------------------
//
//  returns the position of a graph node selected at random
//-----------------------------------------------------------------------------
Vector2D Tile_Map1::GetRandomNodeLocation()const
{
    NavGraph::ConstNodeIterator NodeItr(*m_pNavGraph);
    int RandIndex = RandInt(0, m_pNavGraph->NumActiveNodes() - 1);
    const NavGraph::NodeType* pN = NodeItr.begin();
    while (--RandIndex > 0)
    {
        pN = NodeItr.next();
    }

    return pN->Pos();
}


//--------------------------- Render ------------------------------------------
//-----------------------------------------------------------------------------
void Tile_Map1::Render()
{
    //render all the walls
    std::vector<Wall2D*>::const_iterator curWall = m_Walls.begin();
    for (curWall; curWall != m_Walls.end(); ++curWall)
    {
        gdi->ThickBlackPen();
        (*curWall)->Render();
    }

    std::vector<Vector2D>::const_iterator curSp = m_SpawnPoints.begin();
    for (curSp; curSp != m_SpawnPoints.end(); ++curSp)
    {
        gdi->GreyBrush();
        gdi->GreyPen();
        gdi->Circle(*curSp, 7);
    }
}
