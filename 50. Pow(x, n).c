/* 1. 快速幂 + 递归 */
double quickMul(double x, long long size) {
    if (size == 0) {
        return 1.0;
    }
    double y = quickMul(x, size / 2);
    return size % 2 == 0 ? y * y : y * y * x;
}
double myPow(double x, int n){
    bool f = false;
    long long size = n;
    if (size < 0) {
        size *= -1;
        f = true;
    }
    double ans = quickMul(x, size);
    return f ? (1 / ans) : ans;
}

/* 快速幂 + 迭代 */
double quickMul(double x, long long size) {
    double ans = 1.0;
    double x_count = x;
    while (size > 0) {
        if (size % 2 == 1) {
            ans *= x_count;
        }
        x_count *= x_count;
        size /= 2;
    }
    return ans;
}
double myPow(double x, int n){
    long long size = n;
    return size < 0 ? (1.0 / quickMul(x, -size)) : quickMul(x, size);
}