#include <bits/stdc++.h>
using namespace std;

int main() {
  int v, e, q;
  cin >> v >> e >> q;

  vector<string> name(v + 1);
  unordered_map<string, int> mp;

  for (int i = 1; i <= v; i++) {
    cin >> name[i];
    mp[name[i]] = i;
  }

  vector<vector<int>> g(v + 1);
  for (int i = 0; i < e; i++) {
    string a, b;
    cin >> a >> b;
    int u = mp[a];
    int w = mp[b];
    g[u].push_back(w);
    g[w].push_back(u);
  }

  int lg = 1;
  while ((1 << lg) <= v)
    lg++;

  vector<vector<int>> up(lg, vector<int>(v + 1, 0));
  vector<int> dep(v + 1, 0), comp(v + 1, 0), vis(v + 1, 0);

  int cid = 0;

  for (int s = 1; s <= v; s++) {
    if (vis[s])
      continue;

    cid++;
    queue<int> qu;
    qu.push(s);
    vis[s] = 1;
    comp[s] = cid;
    up[0][s] = 0;
    dep[s] = 0;

    while (!qu.empty()) {
      int u = qu.front();
      qu.pop();

      for (int w : g[u]) {
        if (w == up[0][u])
          continue;
        if (vis[w])
          continue;

        vis[w] = 1;
        comp[w] = cid;
        up[0][w] = u;
        dep[w] = dep[u] + 1;
        qu.push(w);
      }
    }
  }

  for (int j = 1; j < lg; j++) {
    for (int i = 1; i <= v; i++) {
      int p = up[j - 1][i];
      up[j][i] = (p == 0 ? 0 : up[j - 1][p]);
    }
  }

  auto kth = [&](int u, int k) {
    for (int j = 0; j < lg; j++) {
      if (k & (1 << j)) {
        u = up[j][u];
        if (u == 0)
          break;
      }
    }
    return u;
  };

  auto lca = [&](int a, int b) {
    if (dep[a] < dep[b])
      swap(a, b);

    int diff = dep[a] - dep[b];
    for (int j = 0; j < lg; j++) {
      if (diff & (1 << j))
        a = up[j][a];
    }

    if (a == b)
      return a;

    for (int j = lg - 1; j >= 0; j--) {
      if (up[j][a] != up[j][b]) {
        a = up[j][a];
        b = up[j][b];
      }
    }

    return up[0][a];
  };

  auto dist = [&](int a, int b) {
    int w = lca(a, b);
    return dep[a] + dep[b] - 2 * dep[w];
  };

  auto node_at_dist = [&](int a, int b, int x) {
    int w = lca(a, b);
    int da = dep[a] - dep[w];
    int db = dep[b] - dep[w];
    int d = da + db;

    if (x <= da) {
      return kth(a, x);
    } else {
      int rem = d - x;
      return kth(b, rem);
    }
  };

  while (q--) {
    string sa, sb;
    int k;
    cin >> sa >> sb >> k;

    int s = mp[sa];
    int t = mp[sb];

    if (k == 0) {
      if (s == t)
        cout << sa << '\n';
      else
        cout << "NO\n";
      continue;
    }

    if (comp[s] != comp[t]) {
      cout << "NO\n";
      continue;
    }

    int d = dist(s, t);

    if (d % k != 0) {
      cout << "NO\n";
      continue;
    }

    int steps = d / k;
    for (int i = 0; i <= steps; i++) {
      int u = node_at_dist(s, t, i * k);
      cout << name[u];
      if (i != steps)
        cout << ' ';
    }
    cout << '\n';
  }
}