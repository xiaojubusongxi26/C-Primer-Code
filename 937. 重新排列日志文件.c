/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct Pair {
    char * log;
    int idx;
};
int logCompare (const void *log1, const void *log2) {
    char *s1 = ((struct Pair *)log1)->log;
    char *s2 = ((struct Pair *)log2)->log;
    char *split1 = strstr(s1, " ");
    char *split2 = strstr(s2, " ");
    bool isDigit1 = isdigit(split1[1]);
    bool isDigit2 = isdigit(split2[1]);
    if (isDigit1 && isDigit2) {
        return ((struct Pair*)log1)->idx - ((struct Pair*)log2)->idx;
    }
    if (!isDigit1 && !isDigit2) {
        int sc = strcmp(split1, split2);
        if (sc != 0) {
            return sc;
        }
        return strcmp(s1, s2);
    }
    return isDigit1 ? 1 : -1;
}
char ** reorderLogFiles(char ** logs, int logsSize, int* returnSize){
    struct Pair * arr = (struct Pair*)malloc(sizeof(struct Pair) * logsSize);
    for (int i = 0; i < logsSize; i++) {
        arr[i].log = logs[i];
        arr[i].idx = i;
    }
    qsort(arr, logsSize, sizeof(struct Pair), logCompare);
    char ** ans = (char**)malloc(sizeof(char*) * logsSize);
    for (int i = 0; i < logsSize; i++) {
        ans[i] = arr[i].log;
    }
    *returnSize = logsSize;
    free(arr);
    return ans;
}