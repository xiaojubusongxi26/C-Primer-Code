char* reverseWords(char* s){
    int len = strlen(s);
    if (len == 0) {
        return s;
    }
    char* res = (char*)malloc(sizeof(char) * (len + 1));
    res[len] = '\0';
    char* stack = (char*)malloc(sizeof(char) * (len + 1));
    int top = 0, index = 0;
    for (int i = len - 1; i >= 0; i--) {
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        while (i >= 0 && s[i] != ' ') {
            stack[top++] = s[i--];
        }
        while (top > 0) {
            res[index++] = stack[--top];
        }
        res[index++] = ' '; //20��
    }
    index--;
    while (index >= 0 && res[index] == ' ') {
        /* ����ַ���ͷ����2�������ϵĿո�ʱ��20�л��ٸ�res����һ���ո� */
        index--;
    }
    res[index + 1] = '\0';
    return res;
}
