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
    int lenLL(ListNode* head){
        int len=0;
        while(head!=NULL){
            head = head->next;
            len++;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = lenLL(head);
        int i=0;
        ListNode* prev= NULL;
        ListNode* curr = head;
        while(curr!=NULL){
            if(i==(len-n)){
                if(prev){
                    prev->next = curr->next;
                }else{
                    head = curr->next;
                }
            }
            else prev = curr;
            // cout<<curr->val<<endl;
            curr=curr->next; 
            i++;

        }
        return head;
        // cout<<len;
        // return head;
    }
};