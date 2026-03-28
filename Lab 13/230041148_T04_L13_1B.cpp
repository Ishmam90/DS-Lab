#include <bits/stdc++.h>
using namespace std;

class LazyMinSegmentTree {
private:
  int n;
  vector<long long> arr, tree, lazy;

  void build(int node, int b, int e) {
    if (b == e) {
      tree[node] = arr[b];
      return;
    }

    int mid = (b + e) / 2;
    int left = node * 2;
    int right = node * 2 + 1;

    build(left, b, mid);
    build(right, mid + 1, e);

    tree[node] = min(tree[left], tree[right]);
  }

  void push(int node, int b, int e) {
    if (lazy[node] == 0)
      return;

    tree[node] += lazy[node];

    if (b != e) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }

    lazy[node] = 0;
  }

  void update(int node, int b, int e, int i, int j, long long val) {
    push(node, b, e);

    if (j < b || e < i)
      return;

    if (i <= b && e <= j) {
      lazy[node] += val;
      push(node, b, e);
      return;
    }

    int mid = (b + e) / 2;
    int left = node * 2;
    int right = node * 2 + 1;

    update(left, b, mid, i, j, val);
    update(right, mid + 1, e, i, j, val);

    tree[node] = min(tree[left], tree[right]);
  }

  long long query(int node, int b, int e, int i, int j) {
    push(node, b, e);

    if (j < b || e < i)
      return LLONG_MAX;

    if (i <= b && e <= j) {
      return tree[node];
    }

    int mid = (b + e) / 2;
    int left = node * 2;
    int right = node * 2 + 1;

    long long q1 = query(left, b, mid, i, j);
    long long q2 = query(right, mid + 1, e, i, j);

    return min(q1, q2);
  }

public:
  LazyMinSegmentTree(const vector<long long> &input) {
    n = (int)input.size() - 1;
    arr = input;
    tree.assign(4 * n + 5, 0);
    lazy.assign(4 * n + 5, 0);
    build(1, 1, n);
  }

  void rangeUpdate(int l, int r, long long val) { update(1, 1, n, l, r, val); }

  long long rangeQuery(int l, int r) { return query(1, 1, n, l, r); }

  void printStatus() {
    int totalNodes = 2 * n - 1;

    for (int i = 1; i <= totalNodes; i++) {
      cout << tree[i];
      if (i < totalNodes)
        cout << " ";
    }
    cout << "\n";

    for (int i = 1; i <= totalNodes; i++) {
      cout << lazy[i];
      if (i < totalNodes)
        cout << " ";
    }
    cout << "\n";
  }
};

int main() {
  int N, Q;
  cin >> N >> Q;

  vector<long long> a(N + 1);
  for (int i = 1; i <= N; i++)
    cin >> a[i];

  LazyMinSegmentTree st(a);
  st.printStatus();

  while (Q--) {
    int type;
    cin >> type;

    if (type == 2) {
      int i, j;
      long long x;
      cin >> i >> j >> x;

      st.rangeUpdate(i, j, x);
      cout << "\n";
      st.printStatus();
    } else if (type == 1) {
      int i, j;
      cin >> i >> j;

      cout << "\n";
      cout << st.rangeQuery(i, j) << "\n";
      st.printStatus();
    }
  }
}