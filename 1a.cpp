#include "include.h"

int main() {
    int c1, c2, res = 0;
    priority_queue<int> q1, q2;

    while (fin >> c1 >> c2) {
        q1.push(c1);
        q2.push(c2);
    }

    while (!q1.empty()) {
        res += abs(q1.top() - q2.top());
        q1.pop();
        q2.pop();
    }

    cout << res;

    return 0;
}