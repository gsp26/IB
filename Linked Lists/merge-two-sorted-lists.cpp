/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20 
  4 -> 11 -> 15
The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* root1, ListNode* root2) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
     if(root1 != NULL && root2 == NULL)
        return root1;
    if(root2 != NULL && root1 == NULL)
        return root2;

    struct ListNode * start = NULL;
    ListNode* temp = NULL;

    if(root1->val > root2->val)
    {
        start = root2;
        root2 = root2->next;
    }
    else
    {
        start = root1;
        root1 = root1->next;
    }

    temp = start;
    while(root1 != NULL && root2 != NULL)
    {
        if(root1->val > root2->val)
        {
            temp->next = root2;
            root2 = root2->next;
        }
        else
        {
            temp->next = root1;
            root1 = root1->next;
        }
        temp = temp->next;
    }

    if(root1 != NULL)
        temp->next = root1;
    if(root2 != NULL)
        temp->next = root2;

    return start;

}
