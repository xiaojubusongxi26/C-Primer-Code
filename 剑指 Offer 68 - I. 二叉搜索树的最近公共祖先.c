/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode* ans = NULL;
    int pNum = p->val;
    int qNum = q->val;
    int num;
    while (root) {
        num = root->val;
        /* ��p��q��ֵ��ͬʱ���ڵ��ڻ���С�ڵ��ڵ�ǰ�ڵ��ֵʱ��˵���õ�������ߵ���������ڵ� */
        if ((pNum >= num && qNum <= num) || (pNum <= num && qNum >= num)) {
            ans = root;
            break;
        } else if (pNum < num) {
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return ans;
}