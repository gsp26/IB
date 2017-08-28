/*
Sort a linked list using insertion sort.

We have explained Insertion Sort at Slide 7 of Arrays

Insertion Sort Wiki has some details on Insertion Sort as well.

Example :

Input : 1 -> 3 -> 2

Return 1 -> 2 -> 3*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(!A || !A->next)
        return A;
    ListNode *sorted = NULL;
    ListNode *list = A;
    
    while(list)
    {
        ListNode* curr = list;
        list = list->next;
        
        if(!sorted || sorted->val >= curr->val)
        {
            curr->next = sorted;
            sorted = curr;
        }
        else
        {
            ListNode* temp = sorted;
            while (temp)
            {
                ListNode* s = temp;
                temp = temp->next;
                
                if (!s->next || s->next->val > curr->val)
                {
                    curr->next = s->next;
                    s->next = curr;
                    break;
                }
            }
        }
    }
    return sorted;
}
