class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode d(0), *t=&d;
        while(a && b){
            if(a->val <b->val) t->next=a, a=a->next;
            else t->next=b, b=b->next;
            t=t->next;
        }
        t->next = a ? a : b;
        return d.next;
    }
};