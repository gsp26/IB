#include<iostream>

using namespace std;

struct tree
{
    int data;
    struct tree * left;
    struct tree * right;
};

void insert(struct tree ** root, int x)
{
    struct tree * node = new tree;
    node->data = x;
    node->left = NULL;
    node->right = NULL;

    if(*root == NULL)
    {
        *root = node;
        return;
    }

    struct tree *temp = *root;
    struct tree *prev;
    while(temp != NULL)
    {
        prev = temp;
        if(x < temp->data)
            temp= temp->left;
        else
            temp = temp->right;
    }
    if(x < prev->data)
        prev->left = node;
    else
        prev->right =node;

    return;
}

void inOrderTraversal(struct tree *root)
{
    if(root == NULL)
        return;
    inOrderTraversal(root->left);
    cout << root->data << "  ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(struct tree *root)
{
    if(root == NULL)
        return;
    cout << root->data << "  ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(struct tree *root)
{
    if(root == NULL)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << "  ";
}

int main()
{
    cout << "Tree and tree traversals >>> " << endl;
    struct tree * root = NULL;
    insert(&root,10);
    insert(&root,11);
    insert(&root,12);
    insert(&root,13);
    cout << "Inorder TRaversal >>> " <<endl;
    inOrderTraversal(root);
    cout << "\nPre order traversal >>> " << endl;
    preOrderTraversal(root);
    cout << "\nPost order traversal >>> " << endl;
    postOrderTraversal(root);



    return 0;

}
