//
// Created by gionimbus on 7/10/25.
//

#include "Node.h"

Node::Node (): x(0), y(0) {}
Node::Node (int x, int y): x(x), y(y) {}

void Node::setGlobalMap (int* map, int width, int height) {
    global_map = map;
    map_width = width;
    map_height = height;
}

int Node::getValue (int px, int py) {
    if (global_map == nullptr)
        return -1;
    if (px < 0 || px >= map_width || py < 0 || py >= map_height)
        return 9;

    return global_map[py * map_width + px];
}

float Node::GoalDistanceEstimate (Node& nodeGoal) {
    return abs(x - nodeGoal.x) + abs(y - nodeGoal.y);
}

bool Node::IsGoal (Node& nodeGoal) {
    if (x == nodeGoal.x && y == nodeGoal.y)
        return true;
    return false;
}

bool Node::GetSuccessors (AStarSearch<Node>* astarsearch, Node* parent_node) {
    int parent_x = -1;
    int parent_y = -1;

    if (parent_node) {
        parent_x = parent_node->x;
        parent_y = parent_node->y;
    }

    Node newNode;

    if ( (getValue(x-1, y) < 9) && !((parent_x == x-1) && (parent_y == y)) ) {
        newNode = Node(x-1, y);
        astarsearch->AddSuccessor(newNode);
    }

    if ( (getValue(x+1, y) < 9) && !((parent_x == x+1) && (parent_y == y)) ) {
        newNode = Node(x+1, y);
        astarsearch->AddSuccessor(newNode);
    }

    if ( (getValue(x, y-1) < 9) && !((parent_x == x) && (parent_y == y-1)) ) {
        newNode = Node(x, y-1);
        astarsearch->AddSuccessor(newNode);
    }

    if ( (getValue(x, y+1) < 9) && !((parent_x == x) && (parent_y == y+1)) ) {
        newNode = Node(x, y+1);
        astarsearch->AddSuccessor(newNode);
    }

    return true;
}

float Node::GetCost (Node& successor) {
    return (float) getValue (x, y);
}

bool Node::IsSameState( Node& rhs) {
    if (x == rhs.x && y == rhs.y)
        return true;
    return false;
}

size_t Node::Hash() {
    size_t h1 = hash<float>{}(x);
    size_t h2 = hash<float>{}(y);
    return h1 ^ (h2 << 1);
}

void Node::PrintNodeInfo() {
    std::cout << "Node position: (" << x << ", " << y << ")" << std::endl;
}

int Node::getX() const {
    return x;
}

int Node::getY() const {
    return y;
}