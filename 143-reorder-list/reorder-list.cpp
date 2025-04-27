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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* temp = head;
        int n = 0;
        while(temp){
            n++;
            temp = temp->next;
        }
        temp = head;

        int count =1;
        while(temp){
            if(count > (n+1)/2){
                st.push(temp);
            }
            if(count == (n+1)/2){
                
            }
            count++;
            temp = temp->next;
        }

        

        temp = head;
        int stack_len = st.size();
        while(!st.empty()){
            ListNode* temp_next;
            ListNode* top = st.top();
            // cout<<top->val<<" ";
            st.pop();
            if(temp->next){
                temp_next = temp->next;
                temp->next = top;
                temp = temp_next;
            }
            // if(!st.empty() && temp->next){
                // temp_next = temp->next;
                top->next = temp;
                // temp = temp_next;

        }
        temp->next = nullptr;
        // return nullptr;

    }
};