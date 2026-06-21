#ifndef GRIDMAP_H
#define GRIDMAP_H

#include <vector>
#include <string>

class GridMap
{
private:
    std::vector<std::string> grid;

public:
    bool loadMap(const std::string& filename);

    void displayMap() const;

    bool isValid(int x, int y) const;

    bool isObstacle(int x, int y) const;

    int getRows() const;

    int getCols() const;

    char getCell(int x, int y) const;

    void markPath(
        const std::vector<std::pair<int,int>>& path
    );

    std::pair<int,int> getStart() const;

    std::pair<int,int> getDestination() const;
};

#endif