int minDeletionSize(char ** strs, int strsSize){
    int count = 0;
    int m = strsSize, n = strlen(strs[0]);
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 1; j < m; j++) {
            if (strs[j][i] - strs[j - 1][i] < 0) {
                break;
            }
        }
        if (j < m) {
            count++;
        }
    }
    return count;
}