
typedef struct {
    char * key;
    int val;
    UT_hash_handle hh;
} HashSetItem;

typedef struct {
    char * key;
    int val;
    UT_hash_handle hh;
} HashMapItem;

#define MAX_STR_LEN 1024
#define MAX(a, b) ((a) > (b) ? (a) : (b))

char * mostCommonWord(char * paragraph, char ** banned, int bannedSize){
    HashSetItem * bannedSet = NULL;
    // 禁用词入哈希表
    for (int i = 0; i < bannedSize; i++) {
        HashSetItem * pSetEntry = NULL;
        HASH_FIND_STR(bannedSet, banned[i], pSetEntry);
        // 若哈希表中不存在当前单词，则入表
        if (NULL == pSetEntry) {
            pSetEntry = (HashSetItem *)malloc(sizeof(HashSetItem));
            pSetEntry->key = banned[i];
            HASH_ADD_STR(bannedSet, key, pSetEntry);
        }
    }
    // 最大重复次数
    int maxFrequency = 0;
    // 返回单词数组
    char * mostCommon = (char*)malloc(sizeof(char) * MAX_STR_LEN);
    HashMapItem * frequencies = NULL;
    char word[MAX_STR_LEN];
    int pos = 0;
    int length = strlen(paragraph);
    for (int i = 0; i <= length; i++) {
        // 如果是字母就保存
        if (i < length && isalpha(paragraph[i])) {
            word[pos++] = tolower(paragraph[i]);
        } else if (pos > 0) {
            HashSetItem * pSetEntry = NULL;
            // 添加'0'位防止上次记录的单词影响这次的单词
            word[pos] = 0;
            HASH_FIND_STR(bannedSet, word, pSetEntry);
            if (NULL == pSetEntry) {
                HashMapItem * pMapEntry = NULL;
                HASH_FIND_STR(frequencies, word, pMapEntry);
                // 已记录的单词中如果没有当前单词，则加入表中
                if (NULL == pMapEntry) {
                    pMapEntry = (HashMapItem *)malloc(sizeof(HashMapItem));
                    pMapEntry->key = (char*)malloc(sizeof(char) * pos);
                    strcpy(pMapEntry->key, word);
                    pMapEntry->val = 1;
                    HASH_ADD_STR(frequencies, key, pMapEntry);
                } else {
                    pMapEntry->val++;
                }
                // 更新单词最大出现次数
                if (pMapEntry->val > maxFrequency) {
                    maxFrequency = pMapEntry->val;
                    strcpy(mostCommon, word);
                }
            }
            pos = 0;
        }
    }
    return mostCommon;
}