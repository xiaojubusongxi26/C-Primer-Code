int maxSubArray(int* nums, int numsSize){
    int maxSum = nums[0], pre = 0;
    for (int i = 0; i < numsSize; i++) {
        pre = fmax(pre + nums[i], nums[i]);
        maxSum = fmax(pre, maxSum);
    }
    return maxSum;
}