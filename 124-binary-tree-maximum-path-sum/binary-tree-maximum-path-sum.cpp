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
    int maxPathSum(TreeNode* root) {
        int max_path = INT_MIN;
        solve(root, max_path);
        return max_path;
    }
    int solve(TreeNode* root, int &max_path){
        if(!root){
            return 0;
        }

        int lsum = max(0, solve(root->left, max_path));
        int rsum = max(0, solve(root->right, max_path));
        max_path = max(max_path, root->val + lsum +rsum);

        return root->val + max(lsum, rsum);
    }
};