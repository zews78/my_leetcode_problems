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
        // int sum =0;
        int carry =0;
        ListNode* head = new ListNode(-1);
        ListNode* dummy = head;
        while(l1 && l2){
            int sum = l1->val + l2->val;
            sum+= carry;
            carry = sum/10;
            sum = sum%10;
            ListNode* temp = new ListNode(sum);
            head->next = temp;
            head = head->next;

            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int sum = l1->val;
            sum+= carry;
            carry = sum/10;
            sum = sum%10;
            ListNode* temp = new ListNode(sum);
            head->next = temp;
            head = head->next;

            l1 = l1->next;
        }
        while(l2){
            int sum = l2->val;
            sum+= carry;
            carry = sum/10;
            sum = sum%10;
            ListNode* temp = new ListNode(sum);
            head->next = temp;
            head = head->next;

            l2 = l2->next;
        }
        if(carry){
            ListNode* temp = new ListNode(carry);
            head->next = temp;
            head = head->next;
        }
        return dummy->next;
    }
};