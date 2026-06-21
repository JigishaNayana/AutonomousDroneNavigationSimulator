#ifndef NODE_H
#define NODE_H

struct Node
{
    int x;
    int y;

    int gCost;
    int hCost;

    Node* parent;

    Node(int x = 0, int y = 0)
        : x(x), y(y), gCost(0), hCost(0), parent(nullptr)
    {
    }

    int fCost() const
    {
        return gCost + hCost;
    }
};

#endif