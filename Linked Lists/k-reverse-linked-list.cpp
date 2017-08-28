/*
Given a singly linked list and an integer K, reverses the nodes of the

list K at a time and returns modified linked list.

 NOTE : The length of the list is divisible by K 
Example :

Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,

You should return 2 -> 1 -> 4 -> 3 -> 6 -> 5

Try to solve the problem using constant extra space.*/

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
ListNode* Solution::reverseList(ListNode* A, int B) {
    return reverse(A,B);
}

