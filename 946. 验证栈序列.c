bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
    if (pushedSize == 0 && poppedSize == 0) {
        return true;
    }
    int * stack = (int *)malloc(sizeof(int) * pushedSize);
    int len = 0, index = 0;
    for (int i = 0; i < pushedSize; i++) {
        stack[len++] = pushed[i];
        // 清空剩余的栈
        while (len > 0) {
            printf("%d %d\n", stack[len - 1], popped[index]);
            if (stack[len - 1] == popped[index]) {
                index++;
                len--;
            } else break;
        }
    }
    return len == 0;
}