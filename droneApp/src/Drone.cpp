#include "../include/Drone.h"

#include <iostream>

Drone::Drone()
{
    batteryLevel = 100;
}

int Drone::getBattery() const
{
    return batteryLevel;
}

void Drone::consumeBattery(int amount)
{
    batteryLevel -= amount;

    if (batteryLevel < 0)
        batteryLevel = 0;
}

bool Drone::hasBattery() const
{
    return batteryLevel > 0;
}

void Drone::travel(
    const std::vector<std::pair<int,int>>& path)
{
    std::cout << "\nDrone Route:\n";

    for (auto step : path)
    {
        std::cout
            << "("
            << step.first
            << ","
            << step.second
            << ") ";

        consumeBattery(2);
    }

    std::cout << std::endl;
}