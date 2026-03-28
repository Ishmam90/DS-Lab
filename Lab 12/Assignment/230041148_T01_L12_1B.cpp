#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<long long> h(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> h[i];

  vector<int> lg(n + 1);
  lg[1] = 0;
  for (int i = 2; i <= n; i++) {
    lg[i] = lg[i / 2] + 1;
  }

  int K = lg[n] + 1;
  vector<vector<long long>> st(K, vector<long long>(n + 1));

  for (int i = 1; i <= n; i++) {
    st[0][i] = h[i];
  }

  for (int j = 1; j < K; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
    }
  }

  auto rangemax = [&](int L, int R) {
    int len = R - L + 1;
    int j = lg[len];
    return max(st[j][L], st[j][R - (1 << j) + 1]);
  };

  int ans = 0;

  for (int i = 0; i < m; i++) {
    int A, B;
    cin >> A >> B;

    int l = min(A, B) + 1;
    int r = max(A, B) - 1;

    if (l > r) {
      ans++;
    } else {
      long long mx = rangemax(l, r);
      if (mx <= h[A])
        ans++;
    }
  }

  cout << ans << '\n';
}