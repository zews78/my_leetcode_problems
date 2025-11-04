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
        vector<int> arr;
        ListNode* dummy = head;
        while(dummy){
            arr.push_back(dummy->val);
            dummy = dummy->next;
        }

        ListNode* dummy2 = head;
        int n=arr.size();
        if(n==0) return head;
        k = k%n;
        int st_ind = n-k;
        // int end_ind = 2n-k-1;
        // for(auto x: arr){
        //     cout<<x<<" ";
        // }

        while(dummy2){
            dummy2->val = arr[st_ind%n];
            // cout<<st_ind<<"-";
            st_ind++;
            dummy2 = dummy2->next;
        }
        return head;
    }
};