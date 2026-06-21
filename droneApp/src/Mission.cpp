#include "../include/Mission.h"

#include <iostream>
#include <stdexcept>

bool Mission::initialize(
    const std::string& mapFile)
{
    return map.loadMap(mapFile);
}

void Mission::executeMission()
{
    try
    {
        auto start = map.getStart();
        auto destination = map.getDestination();

        if(start.first == -1 ||
           destination.first == -1)
        {
            throw std::runtime_error(
                "Start or Destination not found."
            );
        }

        std::cout << "\nOriginal Map\n";
        std::cout << "-------------------\n";

        map.displayMap();

        auto path =
            pathFinder.findPath(
                map,
                start,
                destination
            );

        if(path.empty())
        {
            std::cout
                << "\nNo path exists.\n";

            return;
        }

        std::cout
            << "\nPath Found Successfully\n";

        std::cout
            << "Path Length : "
            << path.size() - 1
            << "\n";

        drone.travel(path);

        map.markPath(path);

        std::cout
            << "\nFinal Map\n";

        std::cout
            << "-------------------\n";

        map.displayMap();

        std::cout
            << "\nBattery Remaining : "
            << drone.getBattery()
            << "%\n";

        if(drone.hasBattery())
        {
            std::cout
                << "Mission Status : SUCCESS\n";
        }
        else
        {
            std::cout
                << "Mission Status : FAILED\n";
        }
    }
    catch(const std::exception& e)
    {
        std::cout
            << "Error : "
            << e.what()
            << std::endl;
    }
}