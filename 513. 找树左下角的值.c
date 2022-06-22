/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfs (struct TreeNode* node, int num, int* ans, int* ansNum) {
    if (node == NULL) {
        return 0;
    }
    if (node->left == NULL && node->right == NULL) {
        if (num >= *ansNum) {
            *ans = node->val;
            *ansNum = num;
        }
    }
    dfs(node->right, num + 1, ans, ansNum);
    dfs(node->left, num + 1, ans, ansNum);
}
int findBottomLeftValue(struct TreeNode* root){
    int ans = root->val;
    int num = 0;
    int ansNum = 0;
    dfs(root, num + 1, &ans, &ansNum);
    return ans;
}