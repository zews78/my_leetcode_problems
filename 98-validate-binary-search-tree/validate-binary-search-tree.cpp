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
    bool isValidBST(TreeNode* root) {
        long long int left = LLONG_MIN;
        long long int right = LLONG_MAX;
        return solve(left, right, root);
    }
    bool solve(long long int left, long long int right, TreeNode* root){
        if(!root) return true;

        if(root->val < left || root->val > right){
            return false;
        }

        long long int val = root->val;


        return (val > left) && (val <right) && solve(left, val, root->left) && solve(val, right, root->right);
    }
};