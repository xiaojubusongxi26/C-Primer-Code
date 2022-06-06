/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void dfs(struct TreeNode* node, int * arr, int* pos) {
    if (node == NULL) {
        return;
    }
    dfs(node->left, arr, pos);
    arr[(*pos)++] = node->val;
    dfs(node->right, arr, pos);
}
bool findTarget(struct TreeNode* root, int k){
    int *arr = (int*)malloc(sizeof(int) * 10000);
    int pos = 0;
    dfs(root, arr, &pos);
    int left = 0, right = pos - 1;
    while (left < right) {
        if (arr[left] + arr[right] > k) {
            right--;
        } else if (arr[left] + arr[right] < k) {
            left++;
        } else {
            return true;
        }
    }
    return false;
}