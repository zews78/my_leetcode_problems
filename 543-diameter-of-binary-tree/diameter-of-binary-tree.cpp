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
    int diameterOfBinaryTree(TreeNode* root) {
        int diam= 0;
        solve(root, diam);
        return diam;
    }
    int solve(TreeNode* root, int &diam){
        if(!root){
            return 0;
        }

        int lh = 1+solve(root->left, diam);
        int rh = 1+solve(root->right, diam);
        diam = max(diam, lh+rh-2);

        return max(lh, rh);
    }
};