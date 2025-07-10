#include <iostream>
#include "Node.h"
#include "stlastar.h"

bool search (Node& nodeStart, Node& nodeGoal) {
    AStarSearch<Node> astarsearch;
    astarsearch.SetStartAndGoalStates(nodeStart, nodeGoal);

    unsigned int searchState;

    do {
        searchState = astarsearch.SearchStep();
    } while (searchState == AStarSearch<Node>::SEARCH_STATE_SEARCHING);

    if (searchState == AStarSearch<Node>::SEARCH_STATE_SUCCEEDED) {
        std::cout << "Search succeeded" << std::endl;
        Node* node = astarsearch.GetSolutionStart();
        while (node != nullptr) {
            node->PrintNodeInfo();
            node = astarsearch.GetSolutionNext();
        }
        astarsearch.FreeSolutionNodes();
    } else if (searchState == AStarSearch<Node>::SEARCH_STATE_FAILED) {
        std::cout << "Search failed" << std::endl;
    }

    astarsearch.EnsureMemoryFreed();

    if (searchState == AStarSearch<Node>::SEARCH_STATE_SUCCEEDED)
        return true;
    return false;
}

void dislayMap (int* map, int width, int height) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (map[y * width + x] == 9)
                std::cout << "#  ";
            else if (map[y * width + x] < 9)
                std::cout << ".  ";
        }
        std::cout << std::endl;
    }
}

int main () {
    // Set up the global map
    const int map_width = 20;
    const int map_height = 20;
    int global_map[] = {
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,   // 00
        1,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,1,   // 01
        1,9,9,1,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 02
        1,9,9,1,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 03
        1,9,1,1,1,1,9,9,1,9,1,9,1,1,1,1,9,9,1,1,   // 04
        1,9,1,1,9,1,1,1,1,9,1,1,1,1,9,1,1,1,1,1,   // 05
        1,9,9,9,9,1,1,1,1,1,1,9,9,9,9,1,1,1,1,1,   // 06
        1,9,9,9,9,9,9,9,9,1,1,1,9,9,9,9,9,9,9,1,   // 07
        1,9,1,1,1,1,1,1,1,1,1,9,1,1,1,1,1,1,1,1,   // 08
        1,9,1,9,9,9,9,9,9,9,1,1,9,9,9,9,9,9,9,1,   // 09
        1,9,1,1,1,1,9,1,1,9,1,1,1,1,1,1,1,1,1,1,   // 10
        1,9,9,9,9,9,1,9,1,9,1,9,9,9,9,9,1,1,1,1,   // 11
        1,9,1,9,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 12
        1,9,1,9,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 13
        1,9,1,1,1,1,9,9,1,9,1,9,1,1,1,1,9,9,1,1,   // 14
        1,9,1,1,9,1,1,1,1,9,1,1,1,1,9,1,1,1,1,1,   // 15
        1,9,9,9,9,1,1,1,1,1,1,9,9,9,9,1,1,1,1,1,   // 16
        1,1,9,9,9,9,9,9,9,1,1,1,9,9,9,1,9,9,9,9,   // 17
        1,9,1,1,1,1,1,1,1,1,1,9,1,1,1,1,1,1,1,1,   // 18
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,   // 19
    };
    Node::setGlobalMap(global_map, map_width, map_height);
    dislayMap(global_map, map_width, map_height);

    // Set up start and goal nodes
    Node nodeStart (0, 0);
    Node nodeGoal (15, 6);

    // Perform the search
    search(nodeStart, nodeGoal);

    return 0;
}
