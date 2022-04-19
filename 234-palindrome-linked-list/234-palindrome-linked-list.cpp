/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL) return false;
        if(head->next==NULL) return true;
        vector<int> temp1, temp2;
        while(head!=NULL){
            temp1.push_back(head->val);
            head = head->next;
        }
        
        temp2 = temp1;
        reverse(temp1.begin(),temp1.end());
        
        
        if(temp2==temp1) return true;
        return false;
    }
};