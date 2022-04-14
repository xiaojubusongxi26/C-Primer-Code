/* 1. strpbrk函数 */
int maxProduct(char ** words, int wordsSize){
    int ans = 0;
    for (int i = 0; i < wordsSize; i++) {
        for (int j = i + 1; j < wordsSize; j++) {
            if (strpbrk(words[i], words[j]) == NULL) {
                ans = fmax(ans, strlen(words[i]) * strlen(words[j]));
            }
        }
    }
    return ans;
}

/* 2. 位运算 */
int maxProduct(char ** words, int wordsSize){
    int masks[wordsSize];
    memset(masks, 0, sizeof(int) * wordsSize);
    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; j < strlen(words[i]); j++) {
            masks[i] |= 1 << words[i][j]-'a';
        }
    }
    int ans =  0;
    for (int i = 0; i < wordsSize; i++) {
        for (int j = i + 1; j < wordsSize; j++) {
            if (masks[i] & masks[j]) continue;
            ans = fmax(ans, strlen(words[i]) * strlen(words[j]));
        }
    }
    return ans;
}