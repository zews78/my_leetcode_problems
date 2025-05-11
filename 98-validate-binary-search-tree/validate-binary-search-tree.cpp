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
        long long left = LLONG_MIN, right= LLONG_MAX;
        if(root==NULL){
            return true;
        }
        return checkValid(root, left, right);
    }

    bool checkValid(TreeNode* root, long long left, long long right){
        if(!root){
            return true;
        }

        
        long long rootVal = root->val;
        // cout<<rootVal<<","<<left<<","<<right<<endl;
        return (rootVal > left) && (rootVal < right) && checkValid(root->left, left, rootVal) && checkValid(root->right, rootVal, right);
    }
};