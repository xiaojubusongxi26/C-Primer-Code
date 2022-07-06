/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* p = head;
    while (p != NULL && p->next != NULL) {
        if (p->val == p->next->val) {
            struct ListNode* t = p->next;
            p->next = p->next->next;
            free(t);
        } else {
            p = p->next;
        }
    }
    return head;
}