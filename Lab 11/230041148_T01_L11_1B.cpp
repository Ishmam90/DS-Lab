#include <climits>
#include <iostream>
#include <list>
#include <map>
using namespace std;

int main() {
    int a, b;
    map<int, list<int>> m;

    cin >> a >> b;

    for (int i = 1; i <= a; i++)
        m[i].push_back(i);

    int compMax = 0, compMap = 0;

    while (b--) {
        int x, y, par1, par2, sizeMap, sizeMax = INT_MIN;
        cin >> x >> y;

        for (auto it : m)
            for (auto it2 : it.second) {
                if (it2 == x)
                    par1 = it.first;
                else if (it2 == y)
                    par2 = it.first;
            }

        if (par1 != par2) {
            for (auto it : m[par2]) {
                m[par1].push_back(par2);
            }
            m.erase(par2);
        }

        sizeMap = m.size();

        for (auto it : m) {
            sizeMax = max(sizeMax, (int)it.second.size());
        }

        if (sizeMap == compMap && sizeMax == compMax)
            cout << "No change" << endl;
        else {
            cout << sizeMap << " " << sizeMax << endl;
            compMap = sizeMap;
            compMax = sizeMax;
        }
    }
}