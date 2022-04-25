/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// �ҵİ汾
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


// �������ƻ����顪��***
int *singleNumbers(int *nums, int numsSize, int *returnSize)
{
    // ��������ص㣺 1. x^0 = x; 2. x^x = 0;
    // ����������¹��ɣ�
    // a^b^c^b = a^c
    // a^b^b = a^(b^b) = a^0 = a
    // ����Ĺؼ��� ������ͬ�� ���� ��������ٸ�����򼴵ý��
    // ��λ��֣�����ȫ��������յõ�������ֵͬ������������԰�λ�룬�ҳ����ǵ�һ����ͬλk�������Դ˻������飬�ٷֱ�ȫ�������ý��
    int *ret = (int *)malloc(sizeof(int) * 2);

    int x = 0;
    int i = 0;
    for (; i < numsSize; i++)
    {
        x ^= nums[i]; // ������㣬ȡ��������ֵͬ�������
    }

    // �ҵ���ֵͬ�������Ҳ��һ����ͬλk (��������)
    int k = 1;
    while ((x & k) == 0)
    {
        k <<= 1;
    }

    // ����kλ���������㽫���黮��Ϊ�����֣�������ֵͬ�ֱ�λ����������������
    // �������ֱַ���� ��� ���㣬����������Լ������ ÿ�������Ǹ���ֵͬ
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
