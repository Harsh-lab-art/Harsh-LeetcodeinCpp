class Solution 
{
    public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode* a=headA,*b=headB;
        while(a!=b)
        {
            a=a?a->next:headA;
            b=b?b->next:headB;
        }
        return a ;
    }
};
