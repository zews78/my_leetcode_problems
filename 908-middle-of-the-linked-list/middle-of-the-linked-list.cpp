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
    ListNode* middleNode(ListNode* head) {
        int length = 0;
        ListNode* dummy = head;
        while(dummy){
            length++;
            dummy = dummy->next;
        }

        int half_len = length/2;
        while(half_len){
            head = head->next;
            half_len--;
        }
        return head;
    }
};