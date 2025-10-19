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

        int carry = 0;

        int temp = 0;
        temp = (l1->val + l2->val + carry);
        carry = temp/10;

            

        ListNode* res = new ListNode(temp%10);
        ListNode* head = res;
        ListNode* h1 =l1->next;
        ListNode* h2 =l2->next;

        while(h1!=nullptr && h2!=nullptr){
            int temp = 0;
            temp = (h1->val + h2->val + carry);
            carry = temp/10;
            

            ListNode* temp_node = new ListNode(temp%10);
            head->next = temp_node;
            head = head->next;

            h1 = h1->next;
            h2 = h2->next;
            
        }
        while(h1!=nullptr){
            int temp = 0;
            temp = (h1->val + carry);
            carry = temp/10;
            

            ListNode* temp_node = new ListNode(temp%10);
            head->next = temp_node;
            head = head->next;

            h1 = h1->next;
        }
        while(h2!=nullptr){
            int temp = 0;
            temp = (h2->val + carry);
            carry = temp/10;
            

            ListNode* temp_node = new ListNode(temp%10);
            head->next = temp_node;
            head = head->next;

            h2 = h2->next;
        }
        if(carry){
            ListNode* temp_node = new ListNode(carry);
            head->next = temp_node;
            head = head->next;

        }

        return res;
    }
};