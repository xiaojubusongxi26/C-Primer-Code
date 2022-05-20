/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct  {
    int start;
    int index;
} Node;
int cmp (const void *pa, const void *pb) {
    return ((Node *)pa)->start - ((Node *)pb)->start;
}
int* findRightInterval(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize){
    Node * startIntervals = (Node *)malloc(sizeof(Node) * intervalsSize);
    for (int i = 0; i < intervalsSize; i++) {
        startIntervals[i].start = intervals[i][0];
        startIntervals[i].index = i;
    }
    qsort(startIntervals, intervalsSize, sizeof(Node), cmp);

    int * ans = (int*)malloc(sizeof(int) * intervalsSize);
    for (int i = 0; i < intervalsSize; i++) {
        int left = 0;
        int right = intervalsSize - 1;
        int targer = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (startIntervals[mid].start >= intervals[i][1]) {
                targer = startIntervals[mid].index;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        ans[i] = targer;
    }
    *returnSize = intervalsSize;
    return ans;
}