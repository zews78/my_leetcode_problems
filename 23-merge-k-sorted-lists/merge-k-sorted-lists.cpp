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
        int n=lists.size();

        //min heap
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        for(int i=0; i<n; i++){
            if(lists[i]){
                pq.push({lists[i]->val, lists[i]});
            }
        }

        pair<int, ListNode*> top;
        if(!pq.empty()){
            top = pq.top();
            pq.pop();

            if(top.second->next){
                pq.push({top.second->next->val, top.second->next});
            }
        }

        ListNode* firstHead = top.second;

        ListNode* dummyNode = firstHead;

        while(!pq.empty()){
            auto topp = pq.top();
            pq.pop();

            if(topp.second->next){
                pq.push({topp.second->next->val, topp.second->next});
            }

            firstHead->next = topp.second;
            firstHead = firstHead->next;
        }

        return dummyNode;

    }
};