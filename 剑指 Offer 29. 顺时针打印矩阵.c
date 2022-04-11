/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if (matrixSize == 0 || matrixColSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    int rows = matrixSize, columns = matrixColSize[0];
    int total = rows * columns;
    int * order = malloc(sizeof(int) * total);
    *returnSize = 0;

    int left = 0, right = columns - 1, top = 0, bottom = rows - 1;
    while (left <= right && top <= bottom) {
        for (int column = left; column <= right; column++) {
            order[(*returnSize)++] = matrix[top][column];
        }
        for (int row = top + 1; row <= bottom; row++) {
            order[(*returnSize)++] = matrix[row][right];
        }
        if (left < right && top < bottom) {
            for (int column = right - 1; column > left; column--) {
                order[(*returnSize)++] = matrix[bottom][column];
            }
            for (int row = bottom; row > top; row--) {
                order[(*returnSize)++] = matrix[row][left];
            }
        }
        left++;
        right--;
        top++;
        bottom--;
    }
    return order;
}