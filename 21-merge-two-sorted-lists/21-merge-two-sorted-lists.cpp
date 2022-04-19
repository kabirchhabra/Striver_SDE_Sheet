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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        
        vector<ListNode*> ans;
        while(list1!=NULL && list2!=NULL){
            if(list1->val >= list2->val){
                ans.push_back(list2);
                list2 = list2->next;
            }
            else{
                ans.push_back(list1);
                list1 = list1->next;
            }
        }
        
        while(list1!=NULL){
            ans.push_back(list1);
            list1=list1->next;
        }
        
        while(list2!=NULL){
            ans.push_back(list2);
            list2 = list2->next;
        }
        
        ListNode* head = ans[0];
        ListNode* temp = head;
        
        for(int i=1;i<ans.size();i++){
            temp->next = ans[i];
            temp = temp->next;
        }
        
        return head;
    }
};