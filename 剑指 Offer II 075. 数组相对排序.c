/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
    int max = 0;
    for (int i = 0; i < arr1Size; i++) {
        max = fmax(max, arr1[i]);
    }
    int arrCount[max + 1];
    memset(arrCount, 0, sizeof(arrCount));
    for (int i = 0; i < arr1Size; i++) {
        arrCount[arr1[i]]++;
    }
    int * ans = (int*)malloc(sizeof(int) * arr1Size);
    *returnSize = 0;
    for (int i = 0; i < arr2Size; i++) {
        int x = arr2[i];
        for (int j = 0; j < arrCount[x]; j++) {
            ans[(*returnSize)++] = x;
        }
        arrCount[x] = 0;
    }
    for (int i = 0; i <= max; i++) {
        for (int j = 0; j < arrCount[i]; j++) {
            ans[(*returnSize)++] = i;
        }
    }
    return ans;
}