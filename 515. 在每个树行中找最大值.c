/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void dfs (struct TreeNode* node, int num, int* arr, int *len) {
    if (node == NULL) {
        return;
    }
    if (num + 1 > *len) {
        (*len)++;
        arr[num] = node->val;
    } else if (node->val > arr[num]) {
        arr[num] = node->val;
    }
    dfs(node->left, num + 1, arr, len);
    dfs(node->right, num + 1, arr, len);
}
int* largestValues(struct TreeNode* root, int* returnSize){
    int *arr = (int*)malloc(sizeof(int) * 1000);
    int len = 0, num = 0;
    dfs(root, num, arr, &len);
    // arr[len] = '\0';
    *returnSize = len;
    return arr;
}