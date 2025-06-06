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
    bool isPalindrome(ListNode* head) {
        stack<ListNode*> st;
        ListNode* curr = head;
        while(curr){
            st.push(curr);
            curr = curr->next;
        }
        while(head){
            // ListNode* top = st.top();
            // cout<<top->val<<" "<<head->val<<endl;
            if(st.top()->val!=head->val){
                return false;
            }
            st.pop();
            head = head->next;
        }
        return true;
    }
};