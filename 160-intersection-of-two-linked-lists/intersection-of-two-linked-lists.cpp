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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* l1 = headA;
        ListNode* l2 = headB;
        ListNode* dummy_l1 = l1;
        ListNode* dummy_l2 = l2;
        int len_l1 =0;
        while(dummy_l1){
            len_l1++;
            dummy_l1 = dummy_l1->next;
        }
        int len_l2 =0;
        while(dummy_l2){
            len_l2++;
            dummy_l2 = dummy_l2->next;
        }

        int total_len = len_l1+len_l2;
        while(total_len){
            if(l1 == l2){
                return l1;
            }
            if(!l1->next){
                l1 = headB;
            }else{
                l1 = l1->next;
            }
            if(!l2->next){
                l2 = headA;
            }else{
                l2 = l2->next;
            }
            total_len--;
        }
        return nullptr;
    }
};