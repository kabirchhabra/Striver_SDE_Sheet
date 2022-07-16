/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        unordered_map<ListNode*, bool> mp;
        while(head!=NULL){
            if(mp[head]) return head;
            
            mp[head]=true;
            head = head->next;  
        }
        return NULL;
    }
};