class Solution {
public:
    bool hasCycle(ListNode *head) {

        if(head == NULL || head->next == NULL) return false;
        ListNode *p, *q;
        p = q = head;
        while(q->next != NULL && q->next->next != NULL){
            if(q->next == p || q->next->next == p) return true;
            p = p->next;
            q = q->next->next;
        }
        return false;
    }
};