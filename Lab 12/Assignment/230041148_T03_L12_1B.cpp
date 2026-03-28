#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int k = log2(n) + 1;
  vector<vector<int>> st(n, vector<int>(k));
  vector<int> lg(n + 1);

  for (int i = 2; i <= n; i++) {
    lg[i] = lg[i / 2] + 1;
  }

  for (int i = 0; i < n; i++) {
    st[i][0] = a[i];
  }

  for (int j = 1; j < k; j++) {
    for (int i = 0; i + (1 << j) - 1 < n; i++) {
      st[i][j] = __gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
  }

  cout << "Ranges to be stored in Sparse Table:\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      if (i + (1 << j) - 1 < n) {
        cout << "(" << i << "," << i + (1 << j) - 1 << ") ";
      }
    }
    cout << "\n";
  }

  cout << "\nStatus of Sparse Table:\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      if (i + (1 << j) - 1 < n) {
        cout << st[i][j] << " ";
      }
    }
    cout << "\n";
  }

  int q;
  cin >> q;

  for (int qi = 1; qi <= q; qi++) {
    int l, r;
    cin >> l >> r;

    int len = r - l + 1;
    int j = lg[len];

    int left_l = l;
    int left_r = l + (1 << j) - 1;

    int right_l = r - (1 << j) + 1;
    int right_r = r;

    int ans = __gcd(st[left_l][j], st[right_l][j]);

    cout << "\nQuery-" << qi << ": GCD=" << ans << " gcd([" << left_l << ","
         << left_r << "],[" << right_l << "," << right_r << "])";
  }
}