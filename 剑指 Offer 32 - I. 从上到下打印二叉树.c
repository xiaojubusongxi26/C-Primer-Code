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
int* levelOrder(struct TreeNode* root, int* returnSize){
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    int* ans = (int *)malloc(sizeof(int) * 1001);
    int len = 0;
    struct TreeNode * p;
    struct TreeNode * queue[1001];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        p = queue[front++];
        ans[len++]  = p->val;
        if (p->left) {
            queue[rear++] = p->left;
        }
        if (p->right) {
            queue[rear++] = p->right;
        }
    }
    *returnSize = len;
    return ans;
}