int cuttingRope(int n){
    if (n <= 3) {
        return n - 1;
    } else if(n == 4) {
        return n;
    }
    long long ans = 1;
    while (n >= 5) {
        ans = (ans * 3) % 1000000007;
        n -= 3;
        printf("%ld\n", ans);
    }
    ans = (ans * n) % 1000000007;
    return ans;
}