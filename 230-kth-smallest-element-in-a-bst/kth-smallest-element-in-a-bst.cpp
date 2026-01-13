/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int smallest= INT_MAX;
        int cnt = k;
        solve(root, cnt, smallest);
        return smallest;
    }
    void solve(TreeNode* root, int &cnt, int &smallest){
        if(!root) return;
        // if(k==0) return;

        solve(root->left, cnt, smallest);
        
        cnt = cnt-1;
        if(cnt==0){
            smallest = root->val;
            return;
        }
        solve(root->right, cnt, smallest);

    }
};