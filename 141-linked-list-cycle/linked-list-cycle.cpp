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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if(head==NULL || head->next==NULL) return false;
        while(fast){
            if(slow->next){
                slow = slow->next;
            }else{
                return false;
            }
            if(fast->next && fast->next->next){
                fast = fast->next->next;
            }else{
                return false;
            }
            
            if(fast == slow){
                return true;
            }
        }
        return false;
    }
};