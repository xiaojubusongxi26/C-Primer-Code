#define MAX_STR_LEN 64
typedef struct {
    char key[MAX_STR_LEN];
    UT_hash_handle hh;
} HashItem;
const static char * MORSE[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", \
                                 "....", "..", ".---", "-.-", ".-..", "--", "-.", \
                                 "---", ".--.", "--.-", ".-.", "...", "-", "..-", \
                                 "...-", ".--", "-..-", "-.--", "--.."};

int uniqueMorseRepresentations(char ** words, int wordsSize){
    HashItem * seen = NULL;
    for (int i = 0; i < wordsSize; i++) {
        HashItem * pEntry = NULL;
        int len = strlen(words[i]);
        int pos = 0;
        char code[MAX_STR_LEN];
        for (int j = 0; j < len; j++) {
            pos += sprintf(code + pos, "%s", MORSE[words[i][j] - 'a']);
        }
        HASH_FIND_STR(seen, code, pEntry);
        if (NULL == pEntry) {
            pEntry = (HashItem *)malloc(sizeof(HashItem));
            strcpy(pEntry->key, code);
            HASH_ADD_STR(seen, key , pEntry);
        }
    }
    int ans = HASH_COUNT(seen);
    HashItem * curr = NULL, * tmp = NULL;
    HASH_ITER(hh, seen, curr, tmp) {
        HASH_DEL(seen, curr);
        free(curr);
    }
    return ans;
}