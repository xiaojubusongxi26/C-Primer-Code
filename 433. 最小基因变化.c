typedef struct {
    char key[16];
    UT_hash_handle hh;
} HashItem;

// ���ϣ�������Ԫ��
bool hashInsert (HashItem ** obj, const char * str) {
    HashItem * pEntry = (HashItem*)malloc(sizeof(HashItem));
    strcpy(pEntry->key, str);
    HASH_ADD_STR(*obj, key, pEntry);
    return true;
}

// �ڹ�ϣ���в���Ԫ��
bool hashFind (HashItem ** obj, const char * str) {
    HashItem * pEntry = NULL;
    HASH_FIND_STR(*obj, str, pEntry);
    if (NULL == pEntry) {
        return false;
    } else {
        return true;
    }
}

void hashFree(HashItem ** obj) {
    HashItem *curr, *tmp;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

int minMutation(char * start, char * end, char ** bank, int bankSize){
    HashItem *cnt = NULL;
    HashItem *visited = NULL;
    char keys[4] = {'A', 'C', 'G', 'T'};
    if (strcmp(start, end) == 0) {
        return 0;
    }
    for (int i = 0; i < bankSize; i++) {
        hashInsert(&cnt, bank[i]);
    }
    if (!hashFind(&cnt, end)) {
        return -1;
    }
    char ** queue = (char**)malloc(sizeof(char*) * bankSize);
    int head = 0, tail = 0;
    queue[tail] = (char *)malloc(sizeof(char) * 16);
    strcpy(queue[tail], start);
    hashInsert(&visited, start);
    tail++;
    int step = 1;
    while (head != tail) {
        int sz = tail - head;
        for (int i = 0; i < sz; i++) {
            char * curr = queue[head++];
            for (int j = 0; j < 8; j++) {
                for (int k = 0; k < 4; k++) {
                    if (keys[k] != curr[j]) {
                        char *next = (char *)malloc(sizeof(char) * 16);
                        strcpy(next, curr);
                        next[j] = keys[k];
                        if (!hashFind(&visited, next) && hashFind(&cnt, next)) {
                            if (strcmp(next, end) == 0) {
                                while (head != tail) {
                                    free(queue[head++]);
                                }
                                hashFree(&cnt);
                                hashFree(&visited);
                                free(queue);
                                return step;
                            }
                            queue[tail++] = next;
                            hashInsert(&visited, next);
                        } else {
                            free(next);
                        }
                    }
                }
            }
            free(curr);
        }
        step++;
    }
    hashFree(&cnt);
    hashFree(&visited);
    free(queue);
    return -1;
}