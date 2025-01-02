#include "include.h"

int main() {

    FILE *input = fopen("input", "r");

    unordered_map<string, vector<string>> graph;
    set<string> nodes;
    set<pair<string, string>> pairs;

    int cnt = 0;

    char line[6];

    while (!feof(input) && fscanf(input, "%s", line)) {
        string a(line, line + 2);
        string b(line + 3, line + 5);

        nodes.insert(a);
        nodes.insert(b);

        graph[a].push_back(b);
        graph[b].push_back(a);

        pairs.insert({a, b});
        pairs.insert({b, a});
    }

    for (string a : nodes) {
        for (string b : graph[a]) {
            for (string c : graph[b]) {
                if ((pairs.find({a, c}) != pairs.end()) && (a[0] == 't' || b[0] == 't' || c[0] == 't')) {
                    cnt++;
                }
            }
        }
    }

    // 6 = 3! (number of permutations a,b,c in a-b-c)
    cout << cnt / 6 << endl;

    fclose(input);

    return 0;
}