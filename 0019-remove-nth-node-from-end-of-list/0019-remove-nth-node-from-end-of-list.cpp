class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *f =&dummy, *s =&dummy;
        while(n--) f=f->next;
        while(f->next) f=f->next, s=s->next;

        s->next = s->next->next;
        return dummy.next;
    }
};