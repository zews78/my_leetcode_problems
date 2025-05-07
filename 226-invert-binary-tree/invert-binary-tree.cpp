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
    // void solve(TreeNode* temp_root){
    //     if(temp_root==NULL){
    //         return;
    //     }

    //     TreeNode* temp;

    //     temp = temp_root->left;
    //     temp_root->left = temp_root->right;
    //     temp_root->right = temp;

    //     solve(temp_root->left);
    //     solve(temp_root->right);
    // }
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return NULL;
        }
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};