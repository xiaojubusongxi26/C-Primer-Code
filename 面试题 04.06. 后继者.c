struct TreeNode* inorderSuccessor(struct TreeNode* root, struct TreeNode* p){
    if (root == NULL) return NULL;

    if (root->val <= p->val) {
        return inorderSuccessor(root->right, p);
    } else {
        struct TreeNode* q = inorderSuccessor(root->left, p);
        return  ((q == NULL) ? root : q);
    }
}
