#ifndef MISSION_H
#define MISSION_H

#include "GridMap.h"
#include "Drone.h"
#include "PathFinder.h"

class Mission
{
private:
    GridMap map;
    Drone drone;
    PathFinder pathFinder;

public:
    bool initialize(
        const std::string& mapFile
    );

    void executeMission();
};

#endif