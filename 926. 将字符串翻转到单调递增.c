#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minFlipsMonoIncr(char * s){
    int n = strlen(s);
    int dp0 = 0, dp1 = 0;
    for (int i = 0; i < n; i++) {
        int dp0New = dp0, dp1New = MIN(dp1, dp0);
        if (s[i] == '1') {
            dp0New++;
        } else {
            dp1New++;
        }
        dp0 = dp0New;
        dp1 = dp1New;
    }
    return MIN(dp1, dp0);
}