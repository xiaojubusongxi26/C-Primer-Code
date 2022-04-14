int maximumWealth(int** accounts, int accountsSize, int* accountsColSize){
    int m = accountsSize, n = *accountsColSize;
    int max = -1;
    for (int i = 0; i < m;i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += accounts[i][j];
        }
        if (sum > max) {
            max = sum;
        }
    }
    return max;
}