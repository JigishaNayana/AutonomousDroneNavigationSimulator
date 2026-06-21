#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "GridMap.h"

#include <vector>
#include <utility>

class PathFinder
{
public:
    std::vector<std::pair<int,int>>
    findPath(
        GridMap& map,
        std::pair<int,int> start,
        std::pair<int,int> destination
    );

private:
    int heuristic(
        int x1,
        int y1,
        int x2,
        int y2
    );
};

#endif