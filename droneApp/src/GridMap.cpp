#include "../include/GridMap.h"

#include <fstream>
#include <iostream>

bool GridMap::loadMap(const std::string& filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
        return false;

    grid.clear();

    std::string line;

    while (getline(file, line))
    {
        if (!line.empty())
            grid.push_back(line);
    }

    file.close();

    return true;
}

void GridMap::displayMap() const
{
    for (const auto& row : grid)
    {
        std::cout << row << std::endl;
    }
}

bool GridMap::isValid(int x, int y) const
{
    return x >= 0 &&
           y >= 0 &&
           x < getRows() &&
           y < getCols();
}

bool GridMap::isObstacle(int x, int y) const
{
    return grid[x][y] == 'X';
}

int GridMap::getRows() const
{
    return static_cast<int>(grid.size());
}

int GridMap::getCols() const
{
    if (grid.empty())
        return 0;

    return static_cast<int>(grid[0].size());
}

char GridMap::getCell(int x, int y) const
{
    return grid[x][y];
}

void GridMap::markPath(
    const std::vector<std::pair<int,int>>& path)
{
    for (auto cell : path)
    {
        int x = cell.first;
        int y = cell.second;

        if (grid[x][y] == '.')
            grid[x][y] = '*';
    }
}

std::pair<int,int> GridMap::getStart() const
{
    for (int i = 0; i < getRows(); i++)
    {
        for (int j = 0; j < getCols(); j++)
        {
            if (grid[i][j] == 'S')
                return {i, j};
        }
    }

    return {-1, -1};
}

std::pair<int,int> GridMap::getDestination() const
{
    for (int i = 0; i < getRows(); i++)
    {
        for (int j = 0; j < getCols(); j++)
        {
            if (grid[i][j] == 'D')
                return {i, j};
        }
    }

    return {-1, -1};
}