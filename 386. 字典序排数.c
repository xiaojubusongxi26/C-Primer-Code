/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void dfs (int* nums, int n, int * len, int num) {
   if (num > n) {
       return;
   }
   for (int i = 1; i <= 10; i++) {
       if (*len >= n || i + num - 1 > n) {
           return;
       }
       nums[(*len)++] = i + num - 1;
       printf("%d\n", *len);
       dfs(nums, n, len, (i + num - 1) * 10);
   }
}
int* lexicalOrder(int n, int* returnSize){
    int * ans = (int *)malloc(sizeof(int) * (n));
    memset(ans, 0, sizeof(int) * (n));
    int len = 0;
    dfs(ans, n, &len, 1);
    *returnSize = n;
    return ans;
}

/* 官方解答 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* lexicalOrder(int n, int* returnSize){
    int * ans = (int *)malloc(sizeof(int) * (n));
    int number = 1;
    for (int i = 0; i < n; i++) {
        ans[i] = number;
        if (number * 10 <= n) {
            number *= 10;
        } else {
            // 达到边界值回退
            while (number % 10 == 9 || number + 1 > n) {
                number /= 10;
            }
            number++;
        }
    }
    *returnSize = n;
    return ans;
}