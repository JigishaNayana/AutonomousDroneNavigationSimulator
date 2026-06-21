#include "../include/PathFinder.h"

#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

struct State
{
    int x;
    int y;

    int g;
    int f;

    bool operator>(const State& other) const
    {
        return f > other.f;
    }
};

int PathFinder::heuristic(
    int x1,
    int y1,
    int x2,
    int y2)
{
    return std::abs(x1 - x2) +
           std::abs(y1 - y2);
}

std::vector<std::pair<int,int>>
PathFinder::findPath(
    GridMap& map,
    std::pair<int,int> start,
    std::pair<int,int> destination)
{
    int rows = map.getRows();
    int cols = map.getCols();

    std::priority_queue<
        State,
        std::vector<State>,
        std::greater<State>
    > open;

    std::vector<std::vector<bool>>
        visited(rows,
        std::vector<bool>(cols, false));

    std::vector<std::vector<std::pair<int,int>>>
        parent(
            rows,
            std::vector<std::pair<int,int>>(
                cols,
                {-1,-1}
            )
        );

    open.push({
        start.first,
        start.second,
        0,
        heuristic(
            start.first,
            start.second,
            destination.first,
            destination.second
        )
    });

    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};

    while (!open.empty())
    {
        State current = open.top();
        open.pop();

        int x = current.x;
        int y = current.y;

        if (visited[x][y])
            continue;

        visited[x][y] = true;

        if (x == destination.first &&
            y == destination.second)
        {
            std::vector<std::pair<int,int>> path;

            while (!(x == start.first &&
                     y == start.second))
            {
                path.push_back({x,y});

                auto p = parent[x][y];

                x = p.first;
                y = p.second;
            }

            path.push_back(start);

            std::reverse(
                path.begin(),
                path.end()
            );

            return path;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!map.isValid(nx, ny))
                continue;

            if (map.isObstacle(nx, ny))
                continue;

            if (visited[nx][ny])
                continue;

            parent[nx][ny] = {x, y};

            int g = current.g + 1;

            int h = heuristic(
                nx,
                ny,
                destination.first,
                destination.second
            );

            open.push({
                nx,
                ny,
                g,
                g + h
            });
        }
    }

    return {};
}