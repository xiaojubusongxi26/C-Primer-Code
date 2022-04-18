/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    // 当找到p，q任意节点时就直接返回，如果其中一个节点在另一个节点下方，则当前的节点一定是最近公共组件
    if (!root || root == q || root == p)
        return root;
    struct TreeNode *l = lowestCommonAncestor(root->left, p, q);
    struct TreeNode *r = lowestCommonAncestor(root->right, p, q);

    // l 和 r同时找到，则说明当前节点为公共祖先
    if (l && r){
        return root;
    }
    
    
    // l 为空就返回r， 否则就返回l
    return !l ? r : l;
}

