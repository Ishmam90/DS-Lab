#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

void adjancencyList(int a, vector<vector<int>> v) {
    for (int i = 1; i <= a; i++) {
        cout << i << ": ";
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

void bfsOrder(int src, vector<bool> visited, vector<vector<int>> v) {
    queue<int> q;

    q.push(src);
    visited[src] = true;

    while (!q.empty()) {
        cout << q.front() << " ";

        for (int i = 0; i < v[q.front()].size(); i++) {
            int neighbor = v[q.front()][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }

        q.pop();
    }

    cout << endl;
}

void distanceFromSource(int a, int src, vector<bool> visited,
                        vector<vector<int>> v) {
    queue<int> q;
    vector<int> distance(a + 1, 0);
    q.push(src);
    visited[src] = true;

    while (!q.empty()) {
        for (int i = 0; i < v[q.front()].size(); i++) {
            int neighbor = v[q.front()][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                distance[neighbor] = distance[q.front()] + 1;
                q.push(neighbor);
            }
        }

        q.pop();
    }

    for (int i = 1; i <= a; i++) {
        cout << i << "(" << distance[i] << ") ";
    }

    cout << endl;
}

void pathsFromSource(int a, int src, vector<bool> visited,
                     vector<vector<int>> v) {
    queue<int> q;
    stack<int> st;
    vector<int> parent(a + 1, 0);
    q.push(src);
    visited[src] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 0; i < v[node].size(); i++) {
            int neighbor = v[node][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }

    for (int i = 1; i <= a; i++) {
        if (i == src) {
            cout << i << ": " << i << endl;
            continue;
        }

        int serial = i;
        while (serial != src && parent[serial] != 0) {
            st.push(serial);
            serial = parent[serial];
        }

        cout << i << ": " << src;
        while (!st.empty()) {
            cout << "->" << st.top();
            st.pop();
        }

        cout << endl;
    }
}

void edges(int a, int src, vector<bool> visited, vector<vector<int>> v) {
    queue<int> q;
    stack<int> st;
    vector<int> parent(a + 1, 0);
    q.push(src);
    visited[src] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 0; i < v[node].size(); i++) {
            int neighbor = v[node][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }

    for (int i = 1; i <= a; i++) {
        if (parent[i] != 0)
            cout << parent[i] << " " << i << endl;
    }
}

int main() {
    int a, b, src;
    cin >> a >> b >> src;

    vector<vector<int>> v(a + 1);
    vector<bool> visited(a + 1, false);

    for (int i = 0; i < b; i++) {
        int x, y;
        cin >> x >> y;

        v[x].push_back(y);
        v[y].push_back(x);
    }

    cout << "Adjacency List: " << endl;
    adjancencyList(a, v);

    cout << "BFS order: ";
    bfsOrder(src, visited, v);
    cout << endl;

    cout << "Distance from source:" << endl;
    distanceFromSource(a, src, visited, v);
    cout << endl;

    cout << "Paths from Source:" << endl;
    pathsFromSource(a, src, visited, v);
    cout << endl;

    cout << "Edges of BFS Tree: " << endl;
    edges(a, src, visited, v);
}