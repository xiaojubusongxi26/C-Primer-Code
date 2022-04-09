/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    int** ans = (int **)malloc(sizeof(int*) * 1001);
    *returnColumnSizes = (int*)calloc(1001, sizeof(int));
    int len = 0;

    struct TreeNode* queue[3001];
    struct TreeNode* p;
    int front = 0, rear = 0;
    int leftOrRight = 1; // 左到右
    queue[rear++] = root;
    while (front < rear) {
        int size = rear - front;
        int* temp = (int*)malloc(sizeof(int)  * size);
        if (leftOrRight == -1) {
            for (int i = 0; i < size; i++) {
                p = queue[front++];
                temp[i] = p->val;
                if (p->right) queue[rear++] = p->right;
                if (p->left) queue[rear++] = p->left;
            }
        } else {
            for (int i = 0; i < size; i++) {
                p = queue[front++];
                temp[size - i - 1] = p->val;
                if (p->right) queue[rear++] = p->right;
                if (p->left) queue[rear++] = p->left;
            }
            // front += size;
        }
        leftOrRight *= -1;
        ans[len] = temp;
        printf("%d\n", rear - front);
        (*returnColumnSizes)[len++] = size;
    }
    *returnSize = len;
    return ans;
}