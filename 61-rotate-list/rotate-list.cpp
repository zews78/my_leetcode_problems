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
    ListNode* rotateRight(ListNode* head, int k) {
        int n=0;
        ListNode* dummy = head;

        while(dummy){
            n++;
            dummy = dummy->next;
        }
        if(n==0) return head;
        k = k%n;
        if(k==0) return head;
        int m = n-k;
        ListNode* temp_head;
        dummy = head;
        while(m-1){
            dummy = dummy->next;
            m--;
        }
        temp_head = dummy->next;
        dummy->next = nullptr;
        dummy = temp_head;
        while(dummy->next){
            dummy = dummy->next;
        }
        dummy->next = head;
        return temp_head;
        
    }
};