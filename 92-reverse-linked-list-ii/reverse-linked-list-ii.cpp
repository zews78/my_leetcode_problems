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
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(head ==nullptr || head->next==nullptr){
            return head;
        }

        ListNode* dummy = new ListNode(0); //1
        dummy->next = head;


        ListNode* prev = dummy;

        int count=1;

        while(head!=nullptr && count<left){
            prev = head; 
            head = head->next;
            count++;
        }

        // Step 2: Remember start of reversal section and its predecessor
        ListNode* beforeSublist = prev; //1
        ListNode* subListStart = head; //2



        int k = count;
        ListNode* dup_head = head; //2
        while(dup_head!=nullptr && k<right){
            dup_head = dup_head->next;
            k++;

        }
        ListNode* subListEnd = dup_head; //4
        ListNode* afterSublist = nullptr;
        if(dup_head){
            afterSublist = dup_head->next; //5
        }


        //reverse
        ListNode* prev_dummy = beforeSublist;
        while(head!=nullptr && count<=right){

            ListNode* next_dummy = head->next;

            head->next = prev_dummy;
            prev_dummy = head;
            head = next_dummy;
            count++;
        }


        //connect
        beforeSublist->next = prev_dummy;
        subListStart->next = afterSublist;

        // ListNode* dummy2= dummy->next; 
        // while(dummy2){
        //     cout<<dummy2->val<<" ";
        //     dummy2 = dummy2->next;
        // }cout<<endl;
        



        // cout<<beforeSublist->val<<" "<<subListStart->val<<" "<<subListEnd->val<<" "<<afterSublist->val<<endl;

        return dummy->next;


    }
};