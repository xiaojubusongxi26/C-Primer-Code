#define MAX(a, b) ((a) > (b) ? (a) : (b))
int maxRotateFunction(int* nums, int numsSize){
    int f = 0, numSum = 0;
    for (int i = 0; i < numsSize; i++) {
        f += i * nums[i];
        numSum += nums[i];
    }
    int res = f;
    for (int i = numsSize - 1; i >= 0; i--) {
        f += numSum - numsSize * nums[i];
        res = MAX(res, f);
    }
    return res;
}