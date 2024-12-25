#include "include.h"

#define SPACE -1

int main() {
    FILE *input = fopen("input", "r");

    int i = 0, max_fd = 0;

    vector<pair<int, int>> disk;

    char ch;
    while ((ch = fgetc(input)) != EOF) {
        const int count = ch - '0';

        if (i % 2 == 0) {
            disk.push_back({i / 2, count});
            max_fd = max(max_fd, i / 2);
        }
        else disk.push_back({SPACE, count});

        i++;
    }

    unsigned long long checksum = 0;

    int n = disk.size();
    int prev = max_fd;

    for (i = n - 1; i >= 0; i--) {
        if (disk[i].first != max_fd) continue;

        for (int j = 0; j < i; j++) {
            if (disk[j].first == SPACE && disk[j].second >= disk[i].second) {
                disk.insert(disk.begin() + j, disk[i]);

                disk[j + 1].second -= disk[i + 1].second;

                disk[i + 1] = {SPACE, disk[i + 1].second};

                i++;
                n++;

                break;
            }
        }

        max_fd--;
    }

    int it = 0;
    for (i = 0; i < n; i++) {
        if (disk[i].first == SPACE) {
            it += disk[i].second;
            continue;
        }

        for (int j = 0; j < disk[i].second; j++) {
            checksum += it * disk[i].first;
            it++;
        }
    }

    cout << checksum << endl;

    fclose(input);

    return 0;
}