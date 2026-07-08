#include <stdlib.h>
#include <string.h>

typedef struct {
    int *val;   // val[key], -1 means absent
} MyHashMap;

MyHashMap* myHashMapCreate() {
    MyHashMap *m = malloc(sizeof(MyHashMap));
    m->val = malloc(1000001 * sizeof(int));
    memset(m->val, -1, 1000001 * sizeof(int));
    return m;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    obj->val[key] = value;
}

int myHashMapGet(MyHashMap* obj, int key) {
    return obj->val[key];
}

void myHashMapRemove(MyHashMap* obj, int key) {
    obj->val[key] = -1;
}

void myHashMapFree(MyHashMap* obj) {
    free(obj->val);
    free(obj);
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/