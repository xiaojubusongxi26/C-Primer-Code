int numSubarrayProductLessThanK(int* nums, int numsSize, int k){
    // 避免全是1的情况
    if (k <= 1) {
        return 0;
    }
    // 双指针进行移动
    int left = 0, right = 0;
    int mul = 1;
    int ans = 0;
    while (right < numsSize) {
        // 计算乘积
        mul *= nums[right];
        // 当连续的乘积大于k时，移动left指针到合适的位置
        while (mul >= k) {
            mul /= nums[left];
            left++;
        }
        // 每次右指针移动获取组合数
        ans += right - left + 1;
        right++;
    }
    return ans;
}