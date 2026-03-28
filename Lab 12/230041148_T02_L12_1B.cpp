#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    arr.push_back(x);
  }

  int maxLog = 0;
  int length = 1;

  while (length <= n) {
    maxLog++;
    length *= 2;
  }

  vector<vector<int>> table(n, vector<int>(maxLog));

  for (int i = 0; i < n; i++) {
    table[i][0] = arr[i];
  }

  for (int i = 1; i < maxLog; i++) {
    int range = 1;

    for (int j = 0; j < i; j++) {
      range = range * 2;
    }

    for (int j = 0; j + range <= n; j++) {
      table[j][i] = min(table[j][i - 1], table[j + range / 2][i - 1]);
    }
  }

  cout << "Ranges to be stored in Sparse Table:" << endl;
  for (int i = 0; i < n; i++) {
    int range = 1;
    for (int j = 0; j < maxLog; j++) {
      if (i + range - 1 < n) {
        cout << "(" << i << "," << i + range - 1 << ")";
      }
      range = range * 2;
    }
    cout << endl;
  }

  cout << endl;
  cout << "Status of Sparse Table:" << endl;
  for (int i = 0; i < n; i++) {
    int range = 1;
    for (int j = 0; j < maxLog; j++) {
      if (i + range <= n)
        cout << table[i][j] << " ";
      range = range * 2;
    }
    cout << endl;
  }

  cout << endl;

  int q;
  cin >> q;

  for (int qi = 1; qi <= q; qi++) {
    int L, R;
    cin >> L >> R;

    int l = L - 1;
    int r = R - 1;

    int len = R - L + 1;
    int k = 0;
    while ((1 << (k + 1)) <= len) {
      k++;
    }

    int power = (1 << k);
    int leftL = L;
    int leftR = L + power - 1;

    int rightL = R - power + 1;
    int rightR = R;

    int ans = min(table[l][k], table[r - power + 1][k]);

    cout << "Query-" << qi << ": ";
    cout << "Min=" << ans << " ";
    cout << "min([" << leftL << "," << leftR << "],[" << rightL << "," << rightR
         << "])" << endl;
  }
}