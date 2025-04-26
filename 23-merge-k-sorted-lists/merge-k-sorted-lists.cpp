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
        priority_queue<pair<int, ListNode*>,vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        int n = lists.size();
        if(n ==0) return nullptr;

        for(int i=0; i<lists.size(); i++){
            ListNode* currHead = lists[i];
            if(currHead){
                pq.push({currHead->val, currHead});
            }
        }
        // cout<<pq.size();

        if(pq.size()==0) return nullptr;

        ListNode* first_head = pq.top().second;
        pq.pop();
        if(first_head->next){
            pq.push({first_head->next->val, first_head->next});
        }
        ListNode* first_head_copy = first_head;

        while(!pq.empty()){
            ListNode* front = pq.top().second;
            pq.pop();

            ListNode* front_next = front->next;
            if(front_next){
                pq.push({front_next->val, front_next});
            }
            first_head->next = front;
            first_head = front;
        }
        return first_head_copy;

        // return nullptr;
    }
};