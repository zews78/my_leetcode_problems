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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry =0;
        ListNode* output = new ListNode();
        ListNode* res = output;
        while(l1 && l2){
            int sum = (l1->val + l2->val + carry);
            carry = sum/10;
            ListNode* temp = new ListNode(sum%10);
            output->next = temp;
            output = temp;

            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            // output->next = l1;
            int sum = l1->val + carry;
            carry = sum/10;
            ListNode* temp = new ListNode(sum%10);
            output->next = temp;
            output = temp;

            l1 = l1->next;
        }
        while(l2){
            // output->next = l2;
            int sum = l2->val + carry;
            carry = sum/10;
            ListNode* temp = new ListNode(sum%10);
            output->next = temp;
            output = temp;

            l2 = l2->next;
        }
        if(carry>0){
            ListNode* temp = new ListNode(carry);
            output->next = temp;
            output = temp;
        }
        return res->next;
    }
};