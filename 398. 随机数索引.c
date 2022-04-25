typedef struct {
    int *nums;
    int len;
} Solution;


Solution* solutionCreate(int* nums, int numsSize) {
    Solution *obj = (Solution*)malloc(sizeof(Solution));
    obj->nums = nums;
    obj->len = numsSize;
    return obj;
}

int solutionPick(Solution* obj, int target) {
    int *temp = (int*)malloc(sizeof(int) * obj->len);
    int size = 0;
    for (int i = 0; i < obj->len; i++) {
        if (obj->nums[i] == target) {
            temp[size++] = i;
        }
    }
    int ret = rand() % size;
    return temp[ret];
}

void solutionFree(Solution* obj) {
    free(obj->nums);
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(nums, numsSize);
 * int param_1 = solutionPick(obj, target);
 
 * solutionFree(obj);
*/