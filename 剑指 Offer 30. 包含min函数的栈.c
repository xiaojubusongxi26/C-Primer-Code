#define MAX_SIZE 10000
typedef struct {
    int data;
    int min;
} Elem;

typedef struct {
    Elem *elem;
    int top;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack * obj = (MinStack*)malloc(sizeof(MinStack));
    obj->elem = (Elem *)malloc(sizeof(Elem) * MAX_SIZE);
    obj->top = -1;
    return obj;
}

void minStackPush(MinStack* obj, int x) {
    if (obj->top > MAX_SIZE) {
        return;
    }
    if (obj->top == -1) {
        obj->elem[obj->top + 1].min = x;
    } else if (obj->elem[obj->top].min > x) {
        obj->elem[obj->top + 1].min = x;
    } else {
        obj->elem[obj->top + 1].min = obj->elem[obj->top].min;
    }
    obj->elem[++obj->top].data = x;
    return;
}

void minStackPop(MinStack* obj) {
    if (obj->top < 0) {
        return;
    }
    obj->top--;
    return;
}

int minStackTop(MinStack* obj) {
    return obj->elem[obj->top].data;
}

int minStackMin(MinStack* obj) {
    return obj->elem[obj->top].min;
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackMin(obj);
 
 * minStackFree(obj);
*/