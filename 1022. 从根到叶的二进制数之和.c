/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int dfs (struct TreeNode * root, int val) {
    if (root == NULL) {
        return 0;
    }
    val = (val << 1) | root->val;
    if (root->left == NULL && root->right == NULL) {
        return val;
    }
    return dfs(root->left, val) + dfs(root->right, val);
}
int sumRootToLeaf(struct TreeNode* root){
    return dfs(root, 0);
}