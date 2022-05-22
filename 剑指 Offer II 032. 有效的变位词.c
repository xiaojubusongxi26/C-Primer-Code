bool isAnagram(char * s, char * t){
    int lens = strlen(s), lent = strlen(t);
    if (lens != lent) {
        return false;
    } else if(lens == 1) {
        return false;
    }
    int *arrs = (int*)malloc(sizeof(int) * 26);
    int *arrt = (int*)malloc(sizeof(int) * 26);
    memset(arrs, 0, sizeof(int) * 26);
    memset(arrt, 0, sizeof(int) * 26);
    for (int i = 0; i < lens; i++) {
        arrs[s[i] - 'a']++;
        arrt[t[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (arrs[i] != arrt[i]) {
            return false;
        }
    }
    return true;
}