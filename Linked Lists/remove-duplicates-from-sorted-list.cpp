/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.*/
ListNode* Solution::deleteDuplicates(ListNode* root) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(root == NULL)
        return root;

    int x = root->val;
    struct ListNode *temp ;
    temp = root->next;
    struct ListNode * prev = root;
    struct ListNode * t1 = NULL;
    while(temp != NULL)
    {
        if(x == temp->val)
        {
            t1 = temp;
            prev->next = temp->next;
            temp = temp->next;
            delete t1;
        }
        else
        {
            prev = temp;
            x = temp->val;
            temp = temp->next;
        }
    }
    return root;

}
