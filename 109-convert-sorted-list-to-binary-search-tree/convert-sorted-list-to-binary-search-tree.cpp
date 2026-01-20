
class Solution {
public:
    pair<ListNode*, ListNode*> getMid(ListNode* head){
        ListNode* mid = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        while(fast && fast->next){
            prev = mid;
            mid = mid->next;
            fast = fast->next->next;
        }
        return {prev, mid};
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head){
            return nullptr;
        }
        if(!head->next){
            return new TreeNode(head->val);
        }
        

        auto [prev, mid] = getMid(head);
        if(prev){
            prev->next = nullptr;
        }

        TreeNode* node = new TreeNode(mid->val);

        node->left = sortedListToBST(head);
        node->right = sortedListToBST(mid->next);

        
        return node;
        
    }
};