/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// 我的版本
 int compare (const void * a, const void *b) {
     return (*(int*)a - *(int*)b);
 }
int* singleNumbers(int* nums, int numsSize, int* returnSize){
    if (numsSize == 2) {
        *returnSize = numsSize;
        return nums;
    }
    int *ans = (int*)malloc(sizeof(int) * 2);
    memset(ans, 0, sizeof(int));
    int len = 0;
    qsort(nums, numsSize, sizeof(int), compare);
    if (nums[0] != nums[1]) {
        ans[len++] = nums[0];
    }
    if (nums[numsSize - 1] != nums[numsSize - 2]) {
        ans[len++] = nums[numsSize - 1];
    }
    if (len < 2) {
        for (int i = 1; i < numsSize - 1; i++) {
            if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1]) {
                ans[len++] = nums[i];
                if (len >= 2) {
                    break;
                }
            }
        }
    }
    *returnSize = 2;
    return ans;
}


// 按二进制划分组——***
int *singleNumbers(int *nums, int numsSize, int *returnSize)
{
    // 异或运算特点： 1. x^0 = x; 2. x^x = 0;
    // 异或满足以下规律：
    // a^b^c^b = a^c
    // a^b^b = a^(b^b) = a^0 = a
    // 此题的关键是 两个不同数 分配 两个组里，再各组异或即得结果
    // 如何划分？可以全组异或，最终得到两个不同值的异或结果，可以按位与，找出他们第一个不同位k，接着以此划分数组，再分别全组异或求得结果
    int *ret = (int *)malloc(sizeof(int) * 2);

    int x = 0;
    int i = 0;
    for (; i < numsSize; i++)
    {
        x ^= nums[i]; // 异或运算，取得两个不同值的异或结果
    }

    // 找到不同值两数的右侧第一个不同位k (划分数组)
    int k = 1;
    while ((x & k) == 0)
    {
        k <<= 1;
    }

    // 利用k位进行与运算将数组划分为两部分，两个不同值分别位于这两部分数组中
    // 对两部分分别进行 异或 运算，利用异或特性即可求得 每部分中那个不同值
    ret[0] = 0,
    ret[1] = 0;
    for (i = 0; i < numsSize; i++)
    {
        if ((nums[i] & k) == 0)
        {
            ret[0] ^= nums[i];
        }
        else
        {
            ret[1] ^= nums[i];
        }
    }

    *returnSize = 2;
    return ret;
}
