#include <bits/stdc++.h>
using namespace std;

int lsb(int x) { return x & (-x); }

int prefixSum(const vector<int> &bit, int idx) {
  int sum = 0;
  while (idx > 0) {
    sum += bit[idx];
    idx -= lsb(idx);
  }
  return sum;
}

int rangeSum(const vector<int> &bit, int l, int r) {
  return prefixSum(bit, r) - prefixSum(bit, l - 1);
}

void update(vector<int> &bit, int n, int idx, int val) {
  while (idx <= n) {
    bit[idx] += val;
    idx += lsb(idx);
  }
}

int main() {
  int N;
  cin >> N;

  vector<int> arr(N + 1);
  for (int i = 1; i <= N; i++)
    cin >> arr[i];

  vector<int> bit = arr;
  for (int i = 1; i <= N; i++) {
    int j = i + lsb(i);
    if (j <= N) {
      bit[j] += bit[i];
    }
  }

  int t;
  cin >> t;

  cout << "Status of Fenwick Tree (idx: value):\n";
  for (int i = 1; i <= N; i++) {
    cout << i << ":" << bit[i];
    if (i != N)
      cout << " ";
  }
  cout << "\n\n";

  while (t--) {
    int type, x, y;
    cin >> type >> x >> y;

    if (type == 1) {
      cout << "Query: Sum=" << rangeSum(bit, x, y) << "\n";
    } else if (type == 2) {
      update(bit, N, x, y);

      cout << "Updated tree: \n";
      for (int i = 1; i <= N; i++) {
        cout << i << ":" << bit[i];
        if (i != N)
          cout << " ";
      }
      cout << "\n";
    }
  }
}