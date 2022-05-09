int* diStringMatch(char * s, int* returnSize) {
    int n = strlen(s), lo = 0, hi = n;
    int *perm = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i < n; ++i) {
        perm[i] = s[i] == 'I' ? lo++ : hi--;
    }
    perm[n] = lo; // ���ʣ��һ��������ʱ lo == hi
    *returnSize = n + 1;
    return perm;
}
