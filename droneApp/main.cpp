#include <iostream>

#include "include/Mission.h"

int main()
{
    Mission mission;

    if (!mission.initialize("maps/city_map.txt"))
    {
        std::cout
            << "Failed to load map."
            << std::endl;

        return 1;
    }

    std::cout
        << "=============================="
        << std::endl;

    std::cout
        << " AUTONOMOUS DRONE NAVIGATOR "
        << std::endl;

    std::cout
        << "=============================="
        << std::endl;

    mission.executeMission();

    return 0;
}