int numSubarrayProductLessThanK(int* nums, int numsSize, int k){
    // ����ȫ��1�����
    if (k <= 1) {
        return 0;
    }
    // ˫ָ������ƶ�
    int left = 0, right = 0;
    int mul = 1;
    int ans = 0;
    while (right < numsSize) {
        // ����˻�
        mul *= nums[right];
        // �������ĳ˻�����kʱ���ƶ�leftָ�뵽���ʵ�λ��
        while (mul >= k) {
            mul /= nums[left];
            left++;
        }
        // ÿ����ָ���ƶ���ȡ�����
        ans += right - left + 1;
        right++;
    }
    return ans;
}