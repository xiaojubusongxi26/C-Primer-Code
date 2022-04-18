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
        /* 当p和q的值不同时大于等于或者小于等于当前节点的值时，说明该点就是两者的最近公共节点 */
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