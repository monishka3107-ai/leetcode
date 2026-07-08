#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    unsigned char bits[125001];   // 10^6+1 bits
} MyHashSet;

MyHashSet* myHashSetCreate() {
    return calloc(1, sizeof(MyHashSet));
}

void myHashSetAdd(MyHashSet* obj, int key) {
    obj->bits[key >> 3] |= (1 << (key & 7));
}

void myHashSetRemove(MyHashSet* obj, int key) {
    obj->bits[key >> 3] &= ~(1 << (key & 7));
}

bool myHashSetContains(MyHashSet* obj, int key) {
    return (obj->bits[key >> 3] >> (key & 7)) & 1;
}

void myHashSetFree(MyHashSet* obj) {
    free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/