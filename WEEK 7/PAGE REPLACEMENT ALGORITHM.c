#include <stdio.h>
#include <stdbool.h>
#define MAX_FRAMES 10
#define MAX_PAGES 50


bool isPageInFrame(int frames[], int page, int frameCount) {
    for (int i = 0; i < frameCount; i++) {
        if (frames[i] == page) {
            return true;
        }
    }
    return false;
}


int fifo(int pages[], int pageCount, int frameCount) {
    int frames[MAX_FRAMES], front = 0, pageFaults = 0;

    for (int i = 0; i < pageCount; i++) {
        if (!isPageInFrame(frames, pages[i], frameCount)) {
            frames[front] = pages[i];
            front = (front + 1) % frameCount;
            pageFaults++;
        }
    }
    return pageFaults;
}


int lru(int pages[], int pageCount, int frameCount) {
    int frames[MAX_FRAMES], lastUsed[MAX_FRAMES], pageFaults = 0;

    for (int i = 0; i < pageCount; i++) {
        if (!isPageInFrame(frames, pages[i], frameCount)) {
            int leastRecentlyUsedIndex = 0;
            for (int j = 1; j < frameCount; j++) {
                if (lastUsed[j] < lastUsed[leastRecentlyUsedIndex]) {
                    leastRecentlyUsedIndex = j;
                }
            }
            frames[leastRecentlyUsedIndex] = pages[i];
            pageFaults++;
        }
        for (int j = 0; j < frameCount; j++) {
            lastUsed[j]++;
        }
        lastUsed[pages[i] % frameCount] = 0;
    }
    return pageFaults;
}


int optimal(int pages[], int pageCount, int frameCount) {
    int frames[MAX_FRAMES], pageFaults = 0;

    for (int i = 0; i < pageCount; i++) {
        if (!isPageInFrame(frames, pages[i], frameCount)) {
            int farthestIndex = -1, replaceIndex = -1;
            for (int j = 0; j < frameCount; j++) {
                int nextUse = pageCount;
                for (int k = i + 1; k < pageCount; k++) {
                    if (frames[j] == pages[k]) {
                        nextUse = k;
                        break;
                    }
                }
                if (nextUse > farthestIndex) {
                    farthestIndex = nextUse;
                    replaceIndex = j;
                }
            }
            frames[replaceIndex] = pages[i];
            pageFaults++;
        }
    }
    return pageFaults;
}

int main() {
    int pages[MAX_PAGES], pageCount, frameCount;

    printf("Enter number of pages: ");
    scanf("%d", &pageCount);
    printf("Enter page sequence: ");
    for (int i = 0; i < pageCount; i++) {
        scanf("%d", &pages[i]);
    }
    printf("Enter number of frames: ");
    scanf("%d", &frameCount);

    printf("FIFO Page Faults: %d\n", fifo(pages, pageCount, frameCount));
    printf("LRU Page Faults: %d\n", lru(pages, pageCount, frameCount));
    printf("Optimal Page Faults: %d\n", optimal(pages, pageCount, frameCount));

    return 0;
}
