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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(-1);
        ListNode* dummy =head;
        while(list1 && list2){
            ListNode* temp = new ListNode;
            if(list1->val <list2->val){
                cout<<list1->val;
                temp->val = list1->val;
                list1 = list1->next;
            }else{
                cout<<list2->val<<"-l2";
                temp->val = list2->val;
                list2 = list2->next;
            }
            head->next = temp;
            head = temp;
        }
        while(list1){
            ListNode* temp = new ListNode;
            temp->val = list1->val;
            list1 = list1->next;
            head->next = temp;
            head = temp;
        }
        while(list2){
            ListNode* temp = new ListNode;
            temp->val = list2->val;
            list2 = list2->next;
            head->next = temp;
            head = temp;
        }
        return dummy->next;
    }
};