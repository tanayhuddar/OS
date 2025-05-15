#include <stdio.h>
#include <stdbool.h>

#define P 5
#define R 3

bool isSafe(int avail[], int max[][R], int allot[][R]) {
    int need[P][R];
    bool finish[P] = {false};
    int safeSeq[P];
    int work[R];

    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            need[i][j] = max[i][j] - allot[i][j];
        }
    }

    for (int i = 0; i < R; i++) {
        work[i] = avail[i];
    }

    int count = 0;
    while (count < P) {
        bool found = false;

        for (int p = 0; p < P; p++) {
            if (!finish[p]) {
                bool canAllocate = true;
                for (int r = 0; r < R; r++) {
                    if (need[p][r] > work[r]) {
                        canAllocate = false;
                        break;
                    }
                }

                if (canAllocate) {
                    for (int r = 0; r < R; r++) {
                        work[r] += allot[p][r];
                    }
                    safeSeq[count++] = p;
                    finish[p] = true;
                    found = true;
                    break;
                }
            }
        }

        if (!found) {
            printf("System is in an unsafe state\n");
            return false;
        }
    }

    printf("System is in a safe state\nSafe sequence is: ");
    for (int i = 0; i < P; i++) {
        printf("P%d ", safeSeq[i]);
    }
    printf("\n");

    return true;
}

int main() {
    int avail[] = {3, 3, 2};

    int max[][R] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    int allot[][R] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    isSafe(avail, max, allot);

    return 0;
}
