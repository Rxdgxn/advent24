#include "include.h"

int main() {
    char line[256];
    int res = 0;

    while (fin.getline(line, 256)) {
        char *p = strtok(line, " ");

        int u1 = atoi(p);
        p = strtok(NULL, " ");
        
        int u2 = atoi(p);
        p = strtok(NULL, " ");

        int sgn = (u1 - u2 < 0 ? -1 : 1);
        int diff = abs(u1 - u2);

        bool problem = false;

        if (diff < 1 || diff > 3) problem = true;

        u1 = u2;
        bool safe = true;

        while (p) {
            u2 = atoi(p);

            int s = (u1 - u2 < 0 ? -1 : 1);
            diff = abs(u1 - u2);

            if (s != sgn || diff < 1 || diff > 3) {
                if (problem) {
                    safe = false;
                    break;
                }
                else problem = true;
            }

            p = strtok(NULL, " ");
            u1 = u2;
        }

        if (safe) res++;
    }

    cout << res;

    return 0;
}