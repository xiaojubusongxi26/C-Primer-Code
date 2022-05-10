/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int lena = 0, lenb = 0;
    struct ListNode *p = headA;
    while (p) {
        lena++;
        p = p->next;
    }
    p = headB;
    while (p) {
        lenb++;
        p = p->next;
    }
    
    struct ListNode *sortList = NULL, *langList = NULL;
    if (lena > lenb) {
        sortList = headB;
        langList = headA;
    } else {
        sortList = headA;
        langList = headB;
    }
    for (int i = 0; i < abs(lenb - lena); i++) {
        langList = langList->next;
    }
    printf("%d %d", langList, sortList);
    while (langList != sortList) {
        langList = langList->next;
        sortList = sortList->next;
    }
    return sortList == NULL ? NULL : sortList;
}