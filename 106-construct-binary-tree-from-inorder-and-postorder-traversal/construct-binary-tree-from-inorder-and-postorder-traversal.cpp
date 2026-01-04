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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> um;
        for(int i=0; i<inorder.size(); i++){
            um[inorder[i]]= i;
        }

        return constructBT(0, inorder.size()-1, 0, postorder.size()-1, inorder, postorder, um);
    }

    TreeNode* constructBT(int sin, int ein, int sp, int ep, vector<int>& inorder, vector<int>& postorder, unordered_map<int, int> &um){
        if(sin>ein || sp>ep){
            return nullptr;
        }

        int val = postorder[ep];
        TreeNode* node = new TreeNode(val);

        int idx_in = um[val];
        int left_len_in = idx_in-sin;

        node->left = constructBT(sin, idx_in-1, sp, sp+left_len_in-1, inorder, postorder, um);
        node->right = constructBT(idx_in+1, ein, sp+left_len_in, ep-1, inorder, postorder, um);

        return node;

    }
};