typedef struct {
    double* arr;
    double sum;
    int len;
    int size;
} MovingAverage;

/** Initialize your data structure here. */

MovingAverage* movingAverageCreate(int size) {
    MovingAverage* obj = (MovingAverage*)malloc(sizeof(MovingAverage));
    obj->arr = (double*)malloc(sizeof(double) * (10001));
    obj->sum = 0;
    obj->len = 0;
    obj->size = size;
    return obj;
}

double movingAverageNext(MovingAverage* obj, int val) {
    obj->arr[obj->len++] = val;
    if (obj->len > obj->size) {
        obj->sum -= obj->arr[obj->len - obj->size - 1];
    }
    obj->sum += val;
    // printf("%lf, %d\n", obj->sum, val);
    return (obj->sum / (obj->len > obj->size ? obj->size : obj->len));
}

void movingAverageFree(MovingAverage* obj) {
    free(obj->arr);
    free(obj);
}

/**
 * Your MovingAverage struct will be instantiated and called as such:
 * MovingAverage* obj = movingAverageCreate(size);
 * double param_1 = movingAverageNext(obj, val);
 
 * movingAverageFree(obj);
*/