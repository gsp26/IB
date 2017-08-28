int len(ListNode* head)
 {
    int l = 0;
    while(head->next != NULL)
    {
        ++l;
        head = head->next;
    }
    return l;
 }
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    if(!A || !B)
        return NULL;
    int lenA = len(A);
    int lenB = len(B);
    int lenDiff = lenA - lenB;
    ListNode *pa = A;
    ListNode *pb = B;
    if(lenDiff > 0) {
        while(lenDiff != 0) {
            pa = pa->next;
            lenDiff--;
        }
    }
    else if(lenDiff < 0) {
        while(lenDiff != 0) {
            pb = pb->next;
            lenDiff++;
        }
    }
    while(pa && pb) {
        if(pa == pb)
            return pa;
        pa = pa->next;
        pb = pb->next;
    }
    return NULL;
}
