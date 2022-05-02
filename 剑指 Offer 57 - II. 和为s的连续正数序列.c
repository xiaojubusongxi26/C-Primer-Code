/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    int ** result = (int**)malloc(sizeof(int*) * target);
    int *col = (int*)malloc(sizeof(int) * target);
    int i = 1, m = 0, t = target;
    while (t - i >= 0) {
        t -= i;
        ++i;
    }
    while (t < target && i > 2) {
        --i;
        t += i;
        if (t % i == 0) {
            col[m] = i;
            result[m] = (int*)malloc(sizeof(int) * i);
            for (int k = t / i, j = 0; k < t / i + i;k++, j++) {
                result[m][j] = k;
            }
            m++;
        }
    }
    *returnSize = m;
    *returnColumnSizes = col;
    return result;
}