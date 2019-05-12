/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    
    if (A== NULL)
        return;
    
    queue<TreeLinkNode *> qu;
    qu.push(A);
    TreeLinkNode * prev = NULL;
    qu.push(NULL);
    A->next = NULL;
    while(!qu.empty())
    {
        TreeLinkNode  *temp = qu.front();
        qu.pop_front();
        if(prev)
            prev->next = temp;
        if(temp == NULL && prev == NULL)
            break;
        if(temp == NULL)
        {
            qu.push(NULL);
            prev = NULL;
            continue;
        }
        if(temp->left)
            qu.push(temp->left);
        if(temp->right)
            qu.push(temp->right);
        prev = temp;
    }
}

