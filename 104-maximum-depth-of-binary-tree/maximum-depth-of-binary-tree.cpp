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
    int maxDepth(TreeNode* root) {
        int max_height = 0;
        if(!root) return 0;

        solve(root, max_height, 1);
        return max_height;
    }
    void solve(TreeNode* root, int &max_height, int curr_height){

        if(!root){
            return;
        }

        max_height = max(max_height, curr_height);

        solve(root->left, max_height, curr_height+1);
        solve(root->right, max_height, curr_height+1);
    }
};