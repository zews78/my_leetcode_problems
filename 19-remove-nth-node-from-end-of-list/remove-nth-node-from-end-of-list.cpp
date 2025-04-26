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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode* dummy_head = head;
        while(dummy_head){
            len++;
            dummy_head = dummy_head->next;
        }

        ListNode* prev = nullptr;
        ListNode* temp_head = head;
        
        int index = len-n;
        int curr_index =0;

        if(index == 0){
            ListNode* newHead = new ListNode();
            newHead->next = temp_head->next;
            return newHead->next;
        }
        // else if(index == len-1){
            
        // }

        while(temp_head){
            if(curr_index == index){
                if(index == len-1){
                    prev->next = nullptr;
                }else{
                    prev->next = temp_head->next;
                }
            }
            prev = temp_head;
            temp_head = temp_head ->next;
            curr_index++;
        }
        return head;
    }
};