/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
  ListNode * reverse(ListNode * A,int B)
{
     ListNode * current = A;
   ListNode *next = NULL,*prev = NULL;
   int count = 0;
   
   while(current != NULL && count < B)
   {
       next = current->next;
       current->next = prev;
       prev = current;
       current = next;
       count++;
    }
    if(next != NULL)
        A->next = reverse(next,B);
        
    return prev;
}

ListNode* Solution::swapPairs(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    return reverse(A,2);
}
