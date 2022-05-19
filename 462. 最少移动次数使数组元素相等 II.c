int cmp (const void *pa, const void *pb) {
    return *(int*)pa - *(int*)pb;
}
int minMoves2(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    int ans = 0, x = nums[numsSize / 2];
    for (int i = 0; i < numsSize; i++) {
        ans += abs(nums[i] - x);
    }
    return ans;
}