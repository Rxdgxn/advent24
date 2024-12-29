#include "include.h"

#define MAX 10
#define GRID_SIZE 71

int memory[GRID_SIZE][GRID_SIZE];
int visited[GRID_SIZE][GRID_SIZE];

int dirs[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};

int main() {
    FILE *input = fopen("input", "r");

    char line[MAX];

    // The stupid solution

    while (fgets(line, MAX, input)) {
        for (int i = 0; i < GRID_SIZE; i++)
            for (int j = 0; j < GRID_SIZE; j++)
                visited[i][j] = 0;

        int y, x;

        line[strlen(line) - 1] = '\0';

        char *p = strtok(line, ",");
        x = atoi(p);

        p = strtok(NULL, ",");
        y = atoi(p);

        memory[y][x] = 1;

        int minimum_steps = INT_MAX;
        queue<vector<int>> q;

        q.push({0, 0});
        visited[0][0] = 1;

        while (!q.empty()) {
            const auto t = q.front();
            const int y = t[0], x = t[1], steps = t[2];

            q.pop();

            if (y == GRID_SIZE - 1 && x == GRID_SIZE - 1) {
                minimum_steps = min(minimum_steps, steps);
                break;
            }

            for (int i = 0; i < 4; i++) {
                const int ny = y + dirs[i][0];
                const int nx = x + dirs[i][1];

                if (nx >= 0 && ny >= 0 && nx < GRID_SIZE && ny < GRID_SIZE && !visited[ny][nx] && memory[ny][nx] == 0) {
                    q.push({ny, nx, steps + 1});
                    visited[ny][nx] = 1;
                }
            }
        }

        if (minimum_steps == INT_MAX) {
            cout << x << "," << y << endl;
            break;
        }
    }

    fclose(input);

    return 0;
}