char * toGoatLatin(char * sentence){
    int n = strlen(sentence);
    char* ret = (char*)malloc(sizeof(char) * 10001);
    int index = 0;
    int len = 0;
    int f = false;
    char tch;
    for (int i = 0; i < n; i++) {
        // ��¼��������
        if (i == 0 || sentence[i - 1] == ' ') {
            char ch = sentence[i];
            ch = tolower(ch);
            index++;
            // �Ƿ�ΪԪ����ĸ��ͷ
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                f = true;
            } else {
                tch = sentence[i];
                continue;
            }
        }
        // ����ǿո���˵�����˵���ĩβ��������ĸ���
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