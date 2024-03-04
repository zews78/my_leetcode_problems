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
    // void solve(ListNode* head, int val){

    //     //if first element
    //     if(head!=NULL && head->val == val){
    //         ListNode* temp = head;
    //         head= head->next;
    //         // head = temp;
    //         delete temp;
    //     }
    //     //if mid element
    //     while(head!=NULL && head->next!=NULL){

    //     //mid ele
    //         if(head->next->val ==val ){
    //             ListNode* temp = head->next;
    //             head->next = head->next->next;
    //             cout<<head->val<<" ";
    //             // delete temp;
    //         }
    //         //         //if last element
    //         // if(head->next==NULL){
    //         //     head->next = NULL;
    //         // }
    //         head = head->next;
    //     }

    // }
    ListNode* removeElements(ListNode* head, int val) {
        // solve(head, val);
        // if(head!=NULL && head->val == val){
        //     ListNode* temp = head;
        //     head= head->next;
        //     // head = temp;
        //     delete temp;
        // }

        ListNode* curr = head,*prev=NULL;
        while(curr){
            // if(curr->next->val == val){
            //     curr->next = curr->next->next;
            // }
            // curr=curr->next;
            if(curr->val==val){
                if(prev){
                    prev->next=curr->next;
                }else head=curr->next;
            }else prev=curr;
            curr=curr->next;
        }
        
        return head;
    }
};