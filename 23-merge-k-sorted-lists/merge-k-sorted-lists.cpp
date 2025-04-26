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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> sorted_arr;
        for(int i=0; i<lists.size(); i++){
            ListNode* currHead = lists[i];
            while(currHead){
                sorted_arr.push_back(currHead->val);
                currHead = currHead->next;
            }
        }
        sort(sorted_arr.begin(), sorted_arr.end());
        // for(auto x: sorted_arr){
        //     cout<<x<<" ";
        // }
        int n = sorted_arr.size();
        if(n==0) return nullptr;
        
        int first_ele = sorted_arr[0];
        ListNode* newHead = new ListNode(first_ele);
        ListNode* copy_newHead = newHead;

        for(int i=1; i<sorted_arr.size(); i++){
            ListNode* next_node = new ListNode(sorted_arr[i]);
            newHead->next = next_node;
            newHead = next_node;
        }
        return copy_newHead;
        return NULL;
    }
};