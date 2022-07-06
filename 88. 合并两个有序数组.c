void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int tail = m + n - 1;
    int i = m - 1, j = n - 1;
    int temp;
    while (i >= 0 || j >= 0) {
        if (i == -1) {
            temp = nums2[j--];
        } else if (j == -1) {
            temp = nums1[i--];
        } else if (nums1[i] > nums2[j]) {
            temp = nums1[i--];
        } else {
            temp = nums2[j--];
        }
        nums1[tail--] = temp;
    }
}