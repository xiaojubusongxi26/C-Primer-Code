char * toGoatLatin(char * sentence){
    int n = strlen(sentence);
    char* ret = (char*)malloc(sizeof(char) * 10001);
    int index = 0;
    int len = 0;
    int f = false;
    char tch;
    for (int i = 0; i < n; i++) {
        // 记录单词索引
        if (i == 0 || sentence[i - 1] == ' ') {
            char ch = sentence[i];
            ch = tolower(ch);
            index++;
            // 是否为元音字母开头
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                f = true;
            } else {
                tch = sentence[i];
                continue;
            }
        }
        // 如果是空格则说明到了单词末尾，进行子母添加
        if (sentence[i] == ' ') {
            if (!f) {
                ret[len++] = tch;
            }
            ret[len++] = 'm';
            ret[len++] = 'a';
            f = false;
            for (int j = 0; j < index; j++) {
                ret[len++] = 'a';
            }
        }
        ret[len++] = sentence[i];
    }
    if (!f) {
        ret[len++] = tch;
    }
    ret[len++] = 'm';
    ret[len++] = 'a';
    f = false;
    for (int j = 0; j < index; j++) {
        ret[len++] = 'a';
    }
    ret[len] = '\0';
    return ret;
}