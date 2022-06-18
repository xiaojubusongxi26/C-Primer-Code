struct Node* insert(struct Node* head, int insertVal) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->val = insertVal;
    node->next = NULL;
    if (head == NULL) {
        node->next = node;
        return node;
    }
    if (head->next == head) {
        head->next = node;
        node->next = head;
        return head;
    }
    struct Node *curr = head, *next = head->next;
    while (next != head) {
        if (insertVal >= curr->val && insertVal <= next->val) {
            break;
        }
        if (curr->val > next->val) {
            if (insertVal > curr->val || insertVal < next->val) {
                break;
            }
        }
        curr = curr->next;
        next = next->next;
    }
    curr->next = node;
    node->next = next;
    return head;
}