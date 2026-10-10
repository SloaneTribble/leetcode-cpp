#include <iostream>
#include <vector>

// This isn't a specific LeetCode problem, just generic DFS practice

// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
/*
 * Given a connected undirected graph containing V vertices represented by a 2-d adjacency list adj[][],
 *  where each adj[i] represents the list of vertices connected to vertex i.
 * Perform a Depth First Search (DFS) traversal starting from vertex 0, visiting vertices from left to right as per the given adjacency list, and return a list containing the DFS traversal of the graph.
 */


void dfsHelper(int node, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited, std::vector<int>& traversalRecord) {

    visited[node] = true;
    traversalRecord.push_back(node);
    std::vector<int> neighbors = adj[node];

    for (int i = 0; i < neighbors.size(); i++) {
        int neighbor = neighbors[i];
        if (!visited[neighbor]) {
            dfsHelper(neighbor, adj, visited, traversalRecord);
        }
    }
}

std::vector<int> dfs(std::vector<std::vector<int>>& adj) {

    std::vector<bool> visited (adj.size(), false);

    std::vector<int> traversalList;

    // assume the graph is disconnected
    for (int i = 0; i < adj.size(); i++) {
        if (!visited[i]) {
            dfsHelper(i, adj, visited, traversalList);
        }
    }

    return traversalList;

}

int main() {

    std::vector<std::vector<int>> vec = {
        {2, 3, 1},
        {0},
        {0, 4},
        {0},
        {2}
    };

    std::vector<int> traversal = dfs(vec);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
