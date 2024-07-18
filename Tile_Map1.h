#pragma once
#pragma warning (disable:4786)
//-----------------------------------------------------------------------------
//
//  Name:   Raven_Map.h
//
//  Author: Mat Buckland (www.ai-junkie.com)
//
//  Desc:   this class creates and stores all the entities that make up the
//          Raven game environment. (walls, bots, health etc)
//
//          It can read a Raven map editor file and recreate the necessary
//          geometry.
//-----------------------------------------------------------------------------
#include <vector>
#include <string>
#include <list>
#include "TILE_TEST.h"
#include "graph/SparseGraph.h"
#include "Graph/GraphEdgeTypes.h"
#include "Graph/GraphNodeTypes.h"
#include "misc/CellSpacePartition.h"
#include "2d/Wall2D.h"

// 타일 추가할것!

class BaseGameEntity;


class Tile_Map1
{
public:

    typedef NavPosition<TILE_TEST*>         GraphNode;
    typedef SparseGraph<GraphNode, NavEdge>      NavGraph;
    typedef CellSpacePartition<NavGraph::NodeType*>   CellSpace;

public:

    std::vector<Wall2D*>                m_Walls;

    std::vector<Vector2D>              m_SpawnPoints;


    //노드와 엣지를 사용한 스파스그래프임
    NavGraph* m_pNavGraph;

    CellSpace* m_pSpacePartition;

    //the size of the search radius the cellspace partition uses when looking for 
    //neighbors 
    double                             m_dCellSpaceNeighborhoodRange;

    int m_iSizeX;
    int m_iSizeY;

    void  PartitionNavGraph();

    //this will hold a pre-calculated lookup table of the cost to travel from
    //one node to any other.
    std::vector<std::vector<double>>  m_PathCosts;


    //stream constructors for loading from a file
    void AddWall(std::ifstream& in);
    void AddSpawnPoint(std::ifstream& in);
    void Clear();

public:

    Tile_Map1();
    ~Tile_Map1();

    void Render();

    //loads an environment from a file
    bool LoadMap(const std::string& FileName);

    //adds a wall and returns a pointer to that wall. (this method can be
    //used by objects such as doors to add walls to the environment)
    Wall2D* AddWall(Vector2D from, Vector2D to);

    double   CalculateCostToTravelBetweenNodes(int nd1, int nd2)const;

    //returns the position of a graph node selected at random
    Vector2D GetRandomNodeLocation()const;


    const std::vector<Wall2D*>& GetWalls()const { return m_Walls; }
    NavGraph& GetNavGraph()const { return *m_pNavGraph; }
    const std::vector<Vector2D>& GetSpawnPoints()const { return m_SpawnPoints; }
    CellSpace* const                   GetCellSpace()const { return m_pSpacePartition; }
    Vector2D                           GetRandomSpawnPoint() { return m_SpawnPoints[RandInt(0, m_SpawnPoints.size() - 1)]; }
    int                                GetSizeX()const { return m_iSizeX; }
    int                                GetSizeY()const { return m_iSizeY; }
    int                                GetMaxDimension()const { return Maximum(m_iSizeX, m_iSizeY); }
    double                             GetCellSpaceNeighborhoodRange()const { return m_dCellSpaceNeighborhoodRange; }
};