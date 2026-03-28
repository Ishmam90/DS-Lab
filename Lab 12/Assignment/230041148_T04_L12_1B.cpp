#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  vector<int> lg(n + 1);
  for (int i = 2; i <= n; i++) {
    lg[i] = lg[i / 2] + 1;
  }

  int k = lg[n] + 1;
  vector<vector<int>> st(k, vector<int>(n + 1));

  for (int i = 1; i <= n; i++) {
    st[0][i] = a[i];
  }

  for (int j = 1; j < k; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      st[j][i] = st[j - 1][i] | st[j - 1][i + (1 << (j - 1))];
    }
  }

  int q;
  cin >> q;

  while (q--) {
    int l, r, i;
    cin >> l >> r >> i;

    int len = r - l + 1;
    int j = lg[len];

    int ans = st[j][l] | st[j][r - (1 << j) + 1];

    if (ans == a[i])
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}