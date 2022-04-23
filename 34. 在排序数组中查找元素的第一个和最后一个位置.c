/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *ans = (int *)malloc(sizeof(int) * 2);
    ans[0] = -1;
    ans[1] = -1;
    for (int i = 0; i <numsSize; i++) {
        if (nums[i] == target && ans[0] == -1) {
            ans[0] = i;
        }
        if (nums[i] == target) {
            ans[1] = i;
        }
    }
    *returnSize = 2;
    return ans;
}