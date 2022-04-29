void func(struct TreeNode* root, int k ,int *step,int *res)
{
    if(root!=NULL)
    { 
        func(root->right,k,step,res);
        (*step)++;              //���ʽ��ʱ�����Ӳ�����
        if(*step==k)            //������k��Ľ��ʱ����ֵ����res������
        {
            *res=root->val;
            return ;
        }
        func(root->left,k,step,res);
    }
}
int kthLargest(struct TreeNode* root, int k)
{
    int step=0;                 //������¼����
    int res=0;                  //������¼������������k��
    func(root,k,&step,&res);    
    return res;
}


// ����
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