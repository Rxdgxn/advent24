#include "include.h"

#define SPACE -1

int main() {
    FILE *input = fopen("input", "r");

    int i = 0;

    vector<int> disk;

    char ch;
    while ((ch = fgetc(input)) != EOF) {
        const int count = ch - '0';

        for (int j = 0; j < count; j++)
            if (i % 2 == 0) disk.push_back(i / 2);
            else disk.push_back(SPACE);

        i++;
    }

    unsigned long long checksum = 0;

    int st = 0, dr = disk.size() - 1;
    i = 0;

    while (st <= dr) {
        if (disk[st] != SPACE) {
            checksum += (st * disk[st]);

        }
        else {
            while (st < dr && disk[dr] == SPACE) dr--;

            if (st == dr && disk[dr] == SPACE) break;

            checksum += (st * disk[dr--]);
        }

        st++;
    }

    cout << checksum << endl;

    fclose(input);

    return 0;
}