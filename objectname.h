#pragma once
#include <string>


enum
{
    type_wall,
    type_unused,
    type_waypoint,
    type_spawn_point,
    type_obstacle,
};



inline std::string GetNameOfType(int w)
{
    std::string s;

    switch (w)
    {
    case type_wall:

        s = "Wall"; break;

    case type_waypoint:

        s = "Waypoint"; break;

    case type_obstacle:

        s = "Obstacle"; break;

    case type_spawn_point:

        s = "Spawn Point"; break;

    case type_unused:

        s = "knife"; break;

    default:

        s = "UNKNOWN OBJECT TYPE"; break;

    }

    return s;
}


