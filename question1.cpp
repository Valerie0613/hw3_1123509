// Valerie 陳語汝 / 1123509 / 2024.12.11


#include <iostream>
#include <vector>
#include <algorithm>  // Include the algorithm header to use the sort function

using namespace std;

// Function to create an adjacency list for an undirected graph
vector<vector<int>> createAdjacencyList(int V, int E, vector<pair<int, int>>& edges) {
    // Initialize the adjacency list: a vector of V vectors (one for each node)
    vector<vector<int>> adjList(V);

    // Fill the adjacency list with edges
    for (int i = 0; i < E; i++) {
        int u = edges[i].first;  // First node of the edge
        int v = edges[i].second; // Second node of the edge

        // Since it's an undirected graph, add each node to the other's adjacency list
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Sort the adjacency list for each node to ensure neighbors are in ascending order
    for (int i = 0; i < V; i++) {
        sort(adjList[i].begin(), adjList[i].end());  // Sort the neighbors for each node
    }

    return adjList;  // Return the filled adjacency list
}

// Function to print the adjacency list
void printAdjacencyList(const vector<vector<int>>& adjList) {
    // Loop through each node and print its neighbors
    for (int i = 0; i < adjList.size(); i++) {
        cout << i << ": ";  // Print the node number
        // Print all neighbors of the current node
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;  // Move to the next line after printing all neighbors of a node
    }
}

int main() {
    int V, E;  // Number of nodes (V) and edges (E)

    // Prompt the user to input the number of nodes and edges
    cout << "Enter the number of nodes (V) and the number of edges (E): ";
    cin >> V >> E;

    // Initialize a vector to store the edges as pairs of nodes
    vector<pair<int, int>> edges(E);

    // Prompt the user to input the edges
    cout << "Enter " << E << " edges in the format 'node1 node2':" << endl;
    for (int i = 0; i < E; i++) {
        cin >> edges[i].first >> edges[i].second;  // Read each edge as a pair of nodes
    }

    // Create the adjacency list by calling the function
    vector<vector<int>> adjList = createAdjacencyList(V, E, edges);

    // Output the adjacency list
    cout << "Adjacency List:" << endl;
    printAdjacencyList(adjList);

    return 0;  // Return 0 to indicate successful completion
}
