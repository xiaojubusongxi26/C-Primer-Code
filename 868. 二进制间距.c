#define MAX(a, b) ((a) > (b) ? (a) : (b))
int binaryGap(int n){
    int left = 0, size = 0;
    long long temp = 1;
    while (temp < n) {
        temp *= 2;
        size++;
    }
    // ֻ��һ��1��Ϊ0
    if (temp == n) {
        return 0;
    }
    int top = size, max = -1;
    // �������Ƶ�λֵ
    temp /= 2;
    for (int i = size; i > 0; i--) {
        // ��n > temp ��˵����ǰ������λΪ1, top��¼��һ��������λ��λ��
        if (n >= temp) {
            max = MAX(max, top - i);
            n -= temp;
            top = i;
        }
        temp /= 2;
    }
    return max;
}