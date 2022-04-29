/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void maxdfs (struct TreeNode * root, int *max, int deep) {
    if (root == NULL) {
        return;
    }
    if (deep > *max) {
        *max = deep;
    }
    maxdfs(root->left, max, deep + 1);
    maxdfs(root->right, max, deep + 1);
}
int maxDepth(struct TreeNode* root){
    int max = 0;
    maxdfs(root, &max, 1);
    return max;
}