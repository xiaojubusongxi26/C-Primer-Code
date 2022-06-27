static int cmpfunc(const void *a, const void *b) {
    return strlen(*(char**)b) - strlen(*(char**)a);
}
static bool check(char *a, char *b) {
    int i = 0, j = 0;
    int lena = strlen(a);
    int lenb = strlen(b);
    while (i < lena && j < lenb) {
        if (a[i] == b[j]) {
            i++;
            j++;
        } else {
            i++;
        }
    }
    if (j == lenb) {
        return true;
    } else return false;
}
int findLUSlength(char ** strs, int strsSize){
    int i, j, len;
    qsort(strs, strsSize, sizeof(char*), cmpfunc);

    for (i = 0; i < strsSize; i++) {
        bool f = false;
        len = strlen(strs[i]);
        for (j = 0; j < strsSize; j++) {
            if (j == i) {
                continue;
            }
            if (strlen(strs[j]) < len) {
                break;
            }
            if (check(strs[j], strs[i])) {
                f = true;
                break;
            }
        }
        if (!f) {
            return len;
        }
    }
    return -1;
}