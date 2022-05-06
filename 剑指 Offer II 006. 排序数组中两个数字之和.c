/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int* ans = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    int left = 0, right = numbersSize - 1;
    while (left < right) {
        if (numbers[left] + numbers[right] > target) {
            right--;
        } else if (numbers[left] + numbers[right] < target) {
            left++;
        } else {
            ans[0] = left;
            ans[1] = right;
            break;
        }
    }
    return ans;
}