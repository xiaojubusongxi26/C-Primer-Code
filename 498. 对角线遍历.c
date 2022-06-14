/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize){
    int back = -1;
    int n = matSize * (matColSize[0]);
    int * ans = (int*)malloc(sizeof(int) * n);
    int len = 0;
    int i = 0, j = 0;
    while (len < n) {
        ans[len++] = mat[i][j];
        if (back == -1 && (i == 0 || j == matColSize[0] - 1)) {
            back = 1;
            if (j == matColSize[0] - 1) {
                i++;
            } else {
                j++;
            }
        } else if (back == 1 && (j == 0 || i == matSize - 1)) {
            back = -1;
            if (i == matSize - 1) {
                j++;
            } else {
                i++;
            }
            
        } else {
            i += back;
            j -= back;
        }
    }
    *returnSize = n;
    return ans;
}