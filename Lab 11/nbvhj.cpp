#include<iostream>
#include<vector>
using namespace std;

void adjacencyList(int a, vector<vector<int>> v) {
    for (int i = 1; i <= a; i++) {
        cout << i << ": ";
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to classify edges during DFS traversal
void classifyEdge(int u, int v, vector<int>& visited, vector<pair<int, int>>& time) {
    if (visited[v] == 0) {  // Node v is unvisited, tree edge
        cout << u << " " << v << ": Tree Edge" << endl;
    } else if (visited[v] == 1 && time[v].second == 0) {  // v is visited and not finished, back edge
        cout << u << " " << v << ": Back Edge" << endl;
    } else if (visited[v] == 1 && time[v].second > 0) {  // v is finished, forward edge
        cout << u << " " << v << ": Forward Edge" << endl;
    } else {  // Cross edge
        cout << u << " " << v << ": Cross Edge" << endl;
    }
}

// DFS function to explore the graph and classify edges
void dfs(int src, vector<vector<int>>& v, vector<int>& visited, int& count, vector<pair<int, int>>& time, vector<int>& dfsOrder) {
    visited[src] = 1;  // Mark the node as visited
    time[src].first = count;  // Discovery time
    dfsOrder.push_back(src);  // Record the DFS order
    count++;

    // Explore neighbors
    for (int i = 0; i < v[src].size(); i++) {
        int neighbor = v[src][i];
        
        classifyEdge(src, neighbor, visited, time);  // Classify edge
        
        if (visited[neighbor] == 0) {  // If the node is not visited, recursively call DFS
            dfs(neighbor, v, visited, count, time, dfsOrder);
        }
    }

    time[src].second = count;  // Finishing time
    count++;
}

int main() {
    int a, b;
    cin >> a >> b;

    vector<vector<int>> v(a + 1);  // Adjacency list for the graph
    vector<int> visited(a + 1, 0);  // To track visited nodes
    vector<pair<int, int>> time(a + 1);  // To store discovery and finishing times (discovery, finishing)
    vector<int> dfsOrder;  // To track DFS order
    int count = 1;  // Time counter for DFS

    // Reading graph edges
    for (int i = 0; i < b; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);  // Add edge from x to y
    }

    cout << "Adjacency List: " << endl;
    adjacencyList(a, v);
    cout << endl;

    cout << "DFS order: ";
    // Run DFS for every unvisited node
    for (int i = 1; i <= a; i++) {
        if (visited[i] == 0) {
            dfs(i, v, visited, count, time, dfsOrder);  // Start DFS from node i
        }
    }

    // Output DFS order
    for (int i = 0; i < dfsOrder.size(); i++) {
        cout << dfsOrder[i] << " ";
    }
    cout << endl << endl;

    // Output timestamps
    cout << "Timestamps of Vertex (discovery/finishing):" << endl;
    for (int i = 1; i <= a; i++) {
        cout << i << "(" << time[i].first << "/" << time[i].second << ")" << endl;
    }

    return 0;
}