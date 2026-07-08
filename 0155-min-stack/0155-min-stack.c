#include <stdlib.h>

#define MAXN 30001   // at most 3*10^4 operations per constraints

typedef struct {
    int val[MAXN];
    int min[MAXN];   // min of stack up to this position
    int top;
} MinStack;

MinStack* minStackCreate() {
    MinStack *s = malloc(sizeof(MinStack));
    s->top = -1;
    return s;
}

void minStackPush(MinStack* obj, int val) {
    obj->top++;
    obj->val[obj->top] = val;
    obj->min[obj->top] = (obj->top == 0 || val < obj->min[obj->top - 1])
                         ? val : obj->min[obj->top - 1];
}

void minStackPop(MinStack* obj) {
    obj->top--;
}

int minStackTop(MinStack* obj) {
    return obj->val[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->min[obj->top];
}

void minStackFree(MinStack* obj) {
    free(obj);
}