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

    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        solve(root, res);
        return res;

    }
    void solve(TreeNode* root, vector<int> &res){

        if(root->left){
            solve(root->left, res);
        }
        res.push_back(root->val);
        if(root->right){
            solve(root->right, res);
        }
    }
};