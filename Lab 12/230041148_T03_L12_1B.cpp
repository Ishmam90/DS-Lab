#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  vector<int> BIT(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    BIT[i] += arr[i];
    int j = i + (i & -i);
    if (j <= n) {
      BIT[j] += BIT[i];
    }
  }

  cout << "Ranges to be stored in the Fenwick Table:" << endl;
  for (int i = 1; i <= n; i++) {
    int L = i - (i & -i) + 1;
    int R = i;
    cout << i << ":(" << L << "," << R << ") ";
  }
  cout << endl << endl;

  cout << "Status of Fenwick Tree (idx: value):" << endl;
  for (int i = 1; i <= n; i++) {
    cout << i << ":" << BIT[i] << " ";
  }
  cout << endl << endl;

  int q;
  cin >> q;

  for (int qi = 1; qi <= q; qi++) {
    int L, R;
    cin >> L >> R;

    vector<int> rightPath;
    int temp = R;
    while (temp > 0) {
      rightPath.push_back(temp);
      temp -= (temp & -temp);
    }

    vector<int> leftPathPrint;
    temp = L;
    while (temp > 0) {
      leftPathPrint.push_back(temp);
      temp -= (temp & -temp);
    }

    vector<int> leftPathCalc;
    temp = L - 1;
    while (temp > 0) {
      leftPathCalc.push_back(temp);
      temp -= (temp & -temp);
    }

    int sumR = 0;
    for (int idx : rightPath)
      sumR += BIT[idx];

    int sumL = 0;
    for (int idx : leftPathCalc)
      sumL += BIT[idx];

    int ans = sumR - sumL;

    cout << "Query-" << qi << ": ";
    cout << "Sum=" << ans << " [Tree idx: sum(";

    for (int i = 0; i < rightPath.size(); i++) {
      cout << rightPath[i];
      if (i != rightPath.size() - 1)
        cout << ",";
    }

    cout << ") - sum(";

    for (int i = 0; i < leftPathPrint.size(); i++) {
      cout << leftPathPrint[i];
      if (i != leftPathPrint.size() - 1)
        cout << ",";
    }

    cout << ")]" << endl;
  }
}