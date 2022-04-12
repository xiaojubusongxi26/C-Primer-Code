/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberOfLines(int* widths, int widthsSize, char * s, int* returnSize){
    int count = 0;
    int rows = 1;
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        if (widths[s[i] - 'a'] + count > 100) {
            count = widths[s[i] - 'a'];
            rows++;
        } else {
            count += widths[s[i] - 'a'];
        }
    }
    int *ans = malloc(sizeof(int) * 2);
    ans[0] = rows;
    ans[1] = count;
    *returnSize = 2;
    return ans;
}