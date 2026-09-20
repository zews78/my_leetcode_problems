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
    vector<int> nextLargerNodes(ListNode* head) {
        int len_LL = 0;
        ListNode* dummy =head;

        while(dummy){
            dummy=dummy->next;
            len_LL++; 
        }

        vector<int> res(len_LL);
        stack<pair<int, int>> st;

        int idx=0;

        while(head){
            int val = head->val;
            while(!st.empty() && st.top().second<val){
                res[st.top().first]=val;
                st.pop();
            }

            st.push({idx, val});
            idx++;
            head = head->next;
        }

        return res;
    }
};