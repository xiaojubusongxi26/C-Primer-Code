static inline int cmp(const void* pa, const void* pb) {
    return *(int *)pa - *(int *)pb;
}

int findPairs(int* nums, int numsSize, int k){
    qsort(nums, numsSize, sizeof(int), cmp);
    int y = 0, res = 0;
    for (int x = 0; x < numsSize; x++) {
        if (x == 0 || nums[x] != nums[x - 1]) {
            while (y < numsSize && (nums[y] < nums[x] + k || y <= x)) {
                y++;
            }
            if (y < numsSize && nums[y] == nums[x] + k) {
                res++;
            }
        }
    }
    return res;
}
