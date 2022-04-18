/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    // ���ҵ�p��q����ڵ�ʱ��ֱ�ӷ��أ��������һ���ڵ�����һ���ڵ��·�����ǰ�Ľڵ�һ��������������
    if (!root || root == q || root == p)
        return root;
    struct TreeNode *l = lowestCommonAncestor(root->left, p, q);
    struct TreeNode *r = lowestCommonAncestor(root->right, p, q);

    // l �� rͬʱ�ҵ�����˵����ǰ�ڵ�Ϊ��������
    if (l && r){
        return root;
    }
    
    
    // l Ϊ�վͷ���r�� ����ͷ���l
    return !l ? r : l;
}

