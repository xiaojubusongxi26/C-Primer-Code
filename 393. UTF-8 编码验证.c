static const MASK1 = 1 << 7;
static const MASK2 = (1 << 7 ) + (1 << 6);
bool isValid (int num) {
    return (num & MASK2) == MASK1;
}
int getBytes (int num) {
    if ((num & MASK1) == 0) {
        return 1;
    }
    int n = 0;
    int mask = MASK1;
    while ((num & mask) != 0) {
        n++;
        if (n > 4) {
            return -1;
        }
        mask >>= 1;
    }
    return n >= 2 ? n : -1;
}
bool validUtf8(int* data, int dataSize){
    int index = 0;
    while (index <dataSize) {
        int num = data[index];
        int n = getBytes(data[index]);
        if (n < 0 || n + index > dataSize) {
            return false;
        }
        for (int i = 1; i < n; i++) {
            if (!isValid(data[index + i])) {
                return false;
            }
        }
        index += n;
    }
    return true;
}
