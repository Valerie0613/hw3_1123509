// Valerie 陳語汝 / 1123509 / 2024.12.11

#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

// Function to perform DFS traversal and return the traversal order
void dfsTraversal(int node, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& result)
{
    // Mark the current node as visited
    visited[node] = true;

    // Add the current node to the result
    result.push_back(node);

    // Visit all unvisited neighbors of the current node
    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            dfsTraversal(neighbor, adj, visited, result);  // Recursive DFS call
        }
    }
}

int main()
{
    vector<vector<int>> adj;  // Adjacency list for the graph
    string line;

    // Read input until an empty line is provided
    while (getline(cin, line))
    {
        // Check if the input line is empty to stop the loop
        if (line.empty()) break;

        // Create a vector for storing the neighbors of the current vertex
        stringstream ss(line);
        vector<int> neighbors;
        int neighbor;

        // Read all neighbors for the current vertex
        while (ss >> neighbor)
        {
            neighbors.push_back(neighbor);
        }

        // Add the neighbors to the adjacency list
        adj.push_back(neighbors);
    }

    // Prepare visited array and result container
    int V = adj.size();  // Number of vertices in the graph
    vector<bool> visited(V, false);  // Visited array to keep track of visited nodes
    vector<int> result;  // Vector to store the DFS traversal result

    // Start DFS from vertex 0
    dfsTraversal(0, adj, visited, result);

    // Output the DFS traversal result, separated by spaces
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
        if (i < result.size() - 1) cout << " ";  // Add a space between numbers, but not after the last one
    }
    cout << endl;

    return 0;
}
