#include <stdbool.h>
#include <stdlib.h>

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool *vis = calloc(roomsSize, sizeof(bool));
    int *stack = malloc(roomsSize * sizeof(int));
    int top = 0, count = 1;
    stack[top++] = 0;
    vis[0] = true;
    while (top) {
        int r = stack[--top];
        for (int i = 0; i < roomsColSize[r]; i++) {
            int key = rooms[r][i];
            if (!vis[key]) {
                vis[key] = true;
                count++;
                stack[top++] = key;
            }
        }
    }
    bool res = (count == roomsSize);
    free(vis);
    free(stack);
    return res;
}