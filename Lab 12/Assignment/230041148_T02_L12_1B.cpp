#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> a(n + 1), pref(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i] = pref[i - 1] + a[i];
  }

  while (q--) {
    int L, R;
    cin >> L >> R;

    int len = R - L + 1;

    if (len % 2 == 1) {
      cout << -1 << '\n';
      continue;
    }

    int ones = pref[R] - pref[L - 1];
    int zeros = len - ones;

    cout << abs(ones - zeros) / 2 << '\n';
  }
}