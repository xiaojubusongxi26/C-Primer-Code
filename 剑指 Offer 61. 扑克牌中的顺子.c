int compare (const void * a, const void *b) {
    return (*(int*)a - *(int *)b);
}
bool isStraight(int* nums, int numsSize){
    int count = 0;
    qsort(nums, numsSize, sizeof(int), compare);
    for (int i = 0; i < 4; i++) {
        if (nums[i] == 0) {
            count++;
        } else if (nums[i] == nums[i + 1] && nums[i] != 0) {
            return false;
        } else if (nums[i] + 1 != nums[i + 1]) {
            printf("%d", count);
            count = count - (nums[i + 1] - nums[i]) + 1;
            if (count < 0) {
                
                return false;
            }
        }
    }
    return true;
}