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
        if(head==nullptr || head->next==nullptr){
            return nullptr;
        }
        ListNode* dummy = head;
        int len =0;
        while(dummy){
            len++;
            dummy = dummy->next;
        }

        int nth = len-n+1;

        if(nth==1){
            //fist node
            return head->next;
        }
        else if(nth==len){
            //last node
            ListNode* dummy = head;
            while(head){
                if(head->next->next==nullptr){
                    head->next = nullptr;
                    break;
                }
                head = head->next;
            }
            return dummy;
        }else{
            ListNode* dummy = head;
            int counter =1;
            while(head){
                if(counter == nth-1){
                    head->next = head->next->next;
                    break;
                }
                head = head->next;
                counter++;
            }
            return dummy;

        }

        return nullptr;
    }
};