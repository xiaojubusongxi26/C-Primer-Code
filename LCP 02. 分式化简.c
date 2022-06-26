/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* fraction(int* cont, int contSize, int* returnSize){
    int* arr = (int*)malloc(sizeof(int) * 2);
    arr[0] = 1;
    arr[1] = 0;
    for(int i = contSize - 1; i >= 0; i--) {
        int temp = arr[1];
        arr[1] = arr[0];
        arr[0] = temp + cont[i] * arr[1];
    }
    *returnSize = 2;
    return arr;
}