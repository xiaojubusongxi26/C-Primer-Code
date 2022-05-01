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

#define MAXSIZE 5001
void inorder (struct TreeNode* node, int *res, int *pos) {
    if (node) {
        inorder(node->left, res, pos);
        res[(*pos)++] = node->val;
        inorder(node->right, res, pos);
    }
}
int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize){
    int *num1 = (int*)malloc(sizeof(int) * MAXSIZE);
    int *num2 = (int*)malloc(sizeof(int) * MAXSIZE);
    int pos1 = 0, pos2 = 0;
    inorder(root1, num1, &pos1);
    inorder(root2, num2, &pos2);

    int *res = (int*)malloc(sizeof(int) * (pos1 + pos2));
    int pos = 0;
    int p1 = 0, p2 = 0;

    while (true) {
        if (p1 == pos1) {
            memcpy(res + pos, num2 + p2, sizeof(int) * (pos2 - p2));
            break;
        }
        if (p2 == pos2) {
            memcpy(res + pos, num1 + p1, sizeof(int) * (pos1 - p1));
            break;
        }
        if (num1[p1] < num2[p2]) {
            res[pos++] = num1[p1++];
        } else {
            res[pos++] = num2[p2++];
        }
    }
    *returnSize = pos1 + pos2;
    return res;
}