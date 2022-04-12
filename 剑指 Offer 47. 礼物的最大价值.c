int maxValue(int** grid, int gridSize, int* gridColSize){
    int m = gridSize, n = (*gridColSize);
    int ** dp = (int **)malloc(sizeof(int *) * (m + 1));
    dp[0] = (int*)malloc(sizeof(int) * (n + 1));
    memset(dp[0], 0, sizeof(int) * (n + 1));
    for (int i = 1; i <= m; i++) {
        int* column = (int*)malloc(sizeof(int) * (n + 1));
        memset(column, 0, sizeof(int) * (n + 1));
        dp[i] = column;
        for (int j = 1; j <= n; j++) {
            int max = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
            dp[i][j] = max + grid[i - 1][j - 1];
        }
    }
    return dp[m][n];
}