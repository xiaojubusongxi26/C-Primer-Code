#define MAX(a, b) ((a) > (b) ? (a) : (b))
int binaryGap(int n){
    int left = 0, size = 0;
    long long temp = 1;
    while (temp < n) {
        temp *= 2;
        size++;
    }
    // 只有一个1或为0
    if (temp == n) {
        return 0;
    }
    int top = size, max = -1;
    // 最大二进制单位值
    temp /= 2;
    for (int i = size; i > 0; i--) {
        // 当n > temp 则说明当前二进制位为1, top记录上一个二进制位的位置
        if (n >= temp) {
            max = MAX(max, top - i);
            n -= temp;
            top = i;
        }
        temp /= 2;
    }
    return max;
}