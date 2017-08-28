/*
Merge k sorted linked lists and return it as one sorted list.

Example :

1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9
will result in

1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode * start = NULL;
    if(A.size()==0)
        return start;
    if(A.size()==1)
        return A[0];
    priority_queue<pair<int,ListNode*>> pq;
    ListNode * temp = NULL;
    for(int i=0;i<A.size();i++)
    {
        temp = A[i];
        while(temp)
        {
            pq.push(make_pair(temp->val,temp));
            temp = temp->next;
        }
    }
    pair<int,ListNode*> prev = pq.top();
    pq.pop();
    prev.second->next = NULL;
    while(!pq.empty())
    {
        pair<int,ListNode*> temp = pq.top();
        temp.second->next = prev.second;
        prev = temp;
        pq.pop();
    }
    return prev.second;
}
