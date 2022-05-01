/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int left = 0, right = numsSize - 1;
    int* ans = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    while (left < right) {
        int s = nums[left] + nums[right];
        if (s > target) {
            right--;
        } else if (s < target) {
            left++;
        } else {
            ans[0] = nums[left];
            ans[1] = nums[right];
            break;
        }
    }
    return ans;
}