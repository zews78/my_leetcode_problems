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
    int summ=0;
    void solve(TreeNode* root, string val){
        
        if(root->left==NULL && root->right==NULL){
            summ+=stoi(val);
        }

        if(root->left){
            solve(root->left, val+ to_string(root->left->val));
        }
        if(root->right){
            solve(root->right, val+ to_string(root->right->val));
        }
    }
    int sumNumbers(TreeNode* root) {
        string val = "";
        if(root) val += to_string(root->val);
        solve(root, val);
        return summ; 

    }
};