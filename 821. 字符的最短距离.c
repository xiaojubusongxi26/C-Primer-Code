/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestToChar(char * s, char c, int* returnSize){
    int len = strlen(s);
    int * save = (int *)malloc(sizeof(int) * len);
    int n = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == c) {
            save[n++] = i;
        }
    }
    int j = 0;
    int * ret = (int*)malloc(sizeof(int) * len);
    for (int i = 0; i < len ;i++) {
        if ( j < n - 1 && abs(i - save[j]) > abs(i - save[j  +1])) {
            j++;
        }
        ret[i] = abs(i - save[j]);
    }
    *returnSize = len;
    return ret;
}