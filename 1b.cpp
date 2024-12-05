#include "include.h"

ifstream fin("input");

int main() {
    int c1, c2, res = 0;
    unordered_map<int, int> mp;
    vector<int> v;

    while (fin >> c1 >> c2) {
        v.push_back(c1);
        mp[c2]++;
    }

    for (int n : v) {
        res += mp[n] * n;
    }

    cout << res;

    return 0;
}