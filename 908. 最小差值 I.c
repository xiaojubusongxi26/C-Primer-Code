int smallestRangeI(int* nums, int numsSize, int k){
    int max = -1, min = 1000001;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
        if (nums[i] < min) {
            min = nums[i];
        }
    }
    int ans = max - min - (2 * k);
    return ans <= 0 ? 0 : ans;
}