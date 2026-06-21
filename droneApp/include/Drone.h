#ifndef DRONE_H
#define DRONE_H

#include <vector>
#include <utility>

class Drone
{
private:
    int batteryLevel;

public:
    Drone();

    int getBattery() const;

    void consumeBattery(int amount);

    bool hasBattery() const;

    void travel(
        const std::vector<std::pair<int,int>>& path
    );
};

#endif