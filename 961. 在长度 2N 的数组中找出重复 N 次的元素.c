int repeatedNTimes(int* nums, int numsSize) {
    srand(time(NULL));
    while (true) {
        int x = random() % numsSize, y = random() % numsSize;
        if (x != y && nums[x] == nums[y]) {
            return nums[x];
        }
    }
}
