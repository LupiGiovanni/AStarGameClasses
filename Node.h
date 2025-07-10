//
// Created by gionimbus on 7/10/25.
//

#ifndef NODE_H
#define NODE_H

#include "stlastar.h"

class Node {
public:

    Node();
    Node (int x, int y);

    static void setGlobalMap (int* global_map, int map_width, int map_height);
    static int getValue (int px, int py);

    float GoalDistanceEstimate (Node& nodeGoal);
    bool IsGoal (Node& nodeGoal);
    bool GetSuccessors (AStarSearch<Node>* astarsearch, Node* parent_node);
    float GetCost (Node& successor);
    bool IsSameState (Node& rhs);
    size_t Hash();

    void PrintNodeInfo();
    int getX() const;
    int getY() const;

private:
    int x;
    int y;

    inline static int* global_map = nullptr;
    inline static int map_width = 0;
    inline static int map_height = 0;
};

#endif //NODE_H
