/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int compare (const void * a, const void * b) {
     return (*(int *)a - *(int *)b);
 }
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    qsort(arr, arrSize, sizeof(int), compare);
    *returnSize = k;
    return arr;
}