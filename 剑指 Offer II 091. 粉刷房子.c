#define MIN(a, b) ((a) < (b) ? (a) : (b))
int minCost(int** costs, int costsSize, int* costsColSize){
    int dp[3];
    for (int i = 0; i < 3; i++) {
        dp[i] = costs[0][i];
    }
    for (int i = 1; i < costsSize; i++) {
        int dpNew[3];
        for (int j = 0; j < 3; j++) {
            dpNew[j] = MIN(dp[(j + 1) % 3], dp[(j + 2) % 3]) + costs[i][j];
        }
        memcpy(dp, dpNew, sizeof(dpNew));
    }
    int res = INT_MAX;
    for (int i = 0; i < 3; i++) {
        res = MIN(res, dp[i]);
    }
    return res;
}