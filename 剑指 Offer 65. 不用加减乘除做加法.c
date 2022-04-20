int add(int a, int b){
    // 保存同为1的位置，左移一位进行进位
    while (a != 0) {
        // 记录会产生进位的位置
        int temp = a ^ b;
        // 保存二者同为进位值的位置
        a = ((unsigned int) (a & b) << 1);
        b = temp;
    }
    return b;
}