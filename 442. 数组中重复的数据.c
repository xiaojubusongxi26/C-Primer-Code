/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize){
    int * ans = (int*)malloc(sizeof(int) * numsSize);
    int pos = 0;
    for (int i = 0; i < numsSize; i++) {
        int x = abs(nums[i]);
        if (nums[x - 1] > 0) {
            nums[x - 1] *= -1;
        } else {
            ans[pos++] = x;
        }
    }
    *returnSize = pos;
    return ans;
}