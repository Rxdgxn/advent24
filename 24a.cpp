#include "include.h"

#define MAX_SIZE 100

int main() {
    unordered_map<string, int> wires;

    // Careful with CRLF vs LF
    FILE *input = fopen("input", "r");

    char line[MAX_SIZE];

    vector<vector<string>> processed;

    while (fgets(line, MAX_SIZE, input)) {
        // This also means that the input should end with at least a blank line
        line[strlen(line) - 1] = '\0';

        if (strchr(line, ':') != NULL) {
            char *p = strtok(line, ": ");
            string key = p;

            p = strtok(NULL, ": ");
            int value = atoi(p);

            wires[key] = value + 1;
        }
        else {
            if (strlen(line) == 0) continue;

            char *p = strtok(line, " ");
            string w1 = p;

            p = strtok(NULL, " ");
            string gate = p;

            p = strtok(NULL, " ");
            string w2 = p;

            p = strtok(NULL, " ");
            p = strtok(NULL, " ");
            string w3 = p;

            processed.push_back({w1, gate, w2, w3});
        }
    }

    vector<vector<string>> looped;
    do {
        looped.clear();

        for (int i = 0; i < processed.size(); i++) {
            const auto& segm = processed[i];

            if (wires[segm[0]] == 0 || wires[segm[2]] == 0) {
                looped.push_back(segm);
                continue;
            }

            if (segm[1] == "AND") wires[segm[3]] = ((wires[segm[0]] - 1) & (wires[segm[2]] - 1)) + 1;
            else if (segm[1] == "OR") wires[segm[3]] = ((wires[segm[0]] - 1) | (wires[segm[2]] - 1)) + 1;
            else wires[segm[3]] = ((wires[segm[0]] - 1) ^ (wires[segm[2]] - 1)) + 1;
        }

        processed = looped;
    } while (!processed.empty());

    vector<string> keys;
    for (const auto& [k, _] : wires)
        if (k[0] == 'z')
            keys.push_back(k);

    sort(keys.begin(), keys.end());

    long long num = 0;
    long long p = 1;
    for (auto& z_key : keys) {
        num += p * (wires[z_key] - 1);
        p <<= 1;
    }

    cout << num << endl;

    fclose(input);

    return 0;
}