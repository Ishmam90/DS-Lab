#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<string> g;
vector<vector<int>> vis;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y) {
  vis[x][y] = 1;

  for (int d = 0; d < 4; d++) {
    int nx = x + dx[d];
    int ny = y + dy[d];

    if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
      if (!vis[nx][ny] && g[nx][ny] == '1') {
        dfs(nx, ny);
      }
    }
  }
}

int main() {
  cin >> m >> n;

  g.resize(m);
  vis.assign(m, vector<int>(n, 0));

  for (int i = 0; i < m; i++) {
    cin >> g[i];
  }

  int cnt = 0;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (g[i][j] == '1' && !vis[i][j]) {
        cnt++;
        dfs(i, j);
      }
    }
  }

  cout << cnt << '\n';
}