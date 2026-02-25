#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;

    cin >> s;

    int length = s.size();
    vector<vector<int>> prefix(length + 1, vector<int>(26, 0));

    for (int i = 1; i <= length; i++) {
        prefix[i] = prefix[i - 1];
        prefix[i][s[i - 1] - 'a']++;
    }

    int q;
    cin >> q;

    while (q--) {
        int l, r;
        int max = INT_MIN;
        char ans;
        cin >> l >> r;

        for (int i = 0; i < 26; i++) {
            int frequency = prefix[r][i] - prefix[l][i];

            if (frequency > max) {
                max = frequency;
                ans = i + 'a';
            }
        }

        cout << ans << ":" << max << endl;
    }
}