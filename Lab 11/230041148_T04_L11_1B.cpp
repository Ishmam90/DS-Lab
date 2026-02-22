#include <iostream>
#include <vector>
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

void classifyEdge(int u, int v, vector<int> &visited,
                  vector<pair<int, int>> &time) {
    if (visited[v] == 0) {
        cout << u << " " << v << ": Tree Edge" << endl;
    } else if (visited[v] == 1 && time[v].second == 0) {
        cout << u << " " << v << ": Back Edge" << endl;
    } else if (visited[v] == 1 && time[v].second > 0) {
        cout << u << " " << v << ": Forward Edge" << endl;
    } else {
        cout << u << " " << v << ": Cross Edge" << endl;
    }
}

void dfs(int src, vector<vector<int>> &v, vector<int> &visited, int &count,
         vector<pair<int, int>> &time, vector<int> &dfsOrder) {
    visited[src] = 1;
    time[src].first = count;
    dfsOrder.push_back(src);
    count++;

    for (int i = 0; i < v[src].size(); i++) {
        int neighbor = v[src][i];

        classifyEdge(src, neighbor, visited, time);

        if (visited[neighbor] == 0) {
            dfs(neighbor, v, visited, count, time, dfsOrder);
        }
    }

    time[src].second = count;
    count++;
}

int main() {
    int a, b;
    cin >> a >> b;

    vector<vector<int>> v(a + 1);
    vector<int> visited(a + 1, 0);
    vector<pair<int, int>> time(a + 1);
    vector<int> dfsOrder;
    int count = 1;

    for (int i = 0; i < b; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
    }

    cout << "Adjacency List: " << endl;
    adjacencyList(a, v);
    cout << endl;

    cout << "DFS order with Edge Classification: " << endl;
    for (int i = 1; i <= a; i++) {
        if (visited[i] == 0) {
            dfs(i, v, visited, count, time, dfsOrder);
        }
    }

    cout<<endl;
    cout << "DFS Order: ";
    for (int i = 0; i < dfsOrder.size(); i++) {
        cout << dfsOrder[i] << " ";
    }
    cout << endl << endl;

    cout << "Timestamps of Vertex (discovery/finishing):" << endl;
    for (int i = 1; i <= a; i++) {
        cout << i << "(" << time[i].first << "/" << time[i].second << ")"
             << endl;
    }
}