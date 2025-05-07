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
    int max_path = INT_MIN;
    int solve(TreeNode* root){
        if(!root) return 0;

        int left_sum = max(0, solve(root->left));
        int right_sum = max(0, solve(root->right));
        max_path = max(max_path, root->val + left_sum + right_sum);

        return root->val + max(left_sum, right_sum);

    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return max_path;
    }
};