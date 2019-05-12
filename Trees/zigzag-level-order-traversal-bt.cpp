/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    
    vector<vector<int>> res;
    if(A==NULL)
        return res;
        
    stack<TreeNode * > s1;
    stack<TreeNode *> s2;
    vector<int> row;
    
    s1.push(A);
    while(!s1.empty() || !s2.empty())
    {
        row.clear();
        while(!s1.empty())
        {
            TreeNode * temp = s1.top();
            s1.pop();
            row.push_back(temp->val);
            if(temp->left)
                s2.push(temp->left);
            if(temp->right)
                s2.push(temp->right);
        }
        if(row.size() > 0)
            res.push_back(row);
        row.clear();
        while(!s2.empty())
        {
            TreeNode * temp = s2.top();
            s2.pop();
            row.push_back(temp->val);
            if(temp->right)
                s1.push(temp->right);
            if(temp->left)
                s1.push(temp->left);
        }
        if(row.size() > 0)
            res.push_back(row);
    }
    return res;
}
