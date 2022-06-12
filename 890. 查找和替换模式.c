/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool match (char* word, const char* pattern) {
    char mp[256];
    memset(mp, 0, sizeof(mp));
    int len = strlen(word);
    for (int i = 0; i < len; ++i) {
        char x = word[i], y = pattern[i];
        if (!mp[x]) {
            mp[x] = y;
        } else if (mp[x] != y) {
            return false;
        }
    }
    return true;
}
char ** findAndReplacePattern(char ** words, int wordsSize, char * pattern, int* returnSize){
    char ** ans = (char**)malloc(sizeof(char*) * wordsSize);
    int len = 0;
    for (int i = 0; i < wordsSize; i++) {
        if (match(words[i], pattern) && match(pattern, words[i])) {
            ans[len++] = words[i];
        }
    }
    *returnSize = len;
    return ans;
}