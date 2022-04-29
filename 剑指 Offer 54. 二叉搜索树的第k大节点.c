void func(struct TreeNode* root, int k ,int *step,int *res)
{
    if(root!=NULL)
    { 
        func(root->right,k,step,res);
        (*step)++;              //访问结点时，增加步骤数
        if(*step==k)            //当到第k大的结点时，将值存入res，返回
        {
            *res=root->val;
            return ;
        }
        func(root->left,k,step,res);
    }
}
int kthLargest(struct TreeNode* root, int k)
{
    int step=0;                 //用来记录步骤
    int res=0;                  //用来记录搜索二叉树第k项
    func(root,k,&step,&res);    
    return res;
}


// 迭代
#define MaxSize 10000
int kthLargest(struct TreeNode* root, int k)
{
    struct TreeNode* stack[MaxSize];
    int top=-1;
    int step=0,res=0;
    while(root!=NULL||top!=-1)
    {
        while(root!=NULL)
        {
            stack[++top]=root;
            root=root->right;
        }
        if(top!=-1)
        {
            root=stack[top--];
            step++;
            if(step==k)
            {
                res=root->val;
                break;
            }
            root=root->left;
        }
    }
    return res;
}