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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> um;//inorder idx
        for(int i=0; i<inorder.size(); i++){
            um[inorder[i]] = i;
        }
        
        int st_pre =0;
        int end_pre = preorder.size()-1;
        int st_in = 0;
        int end_in = inorder.size()-1;
        return constructBT(st_in, end_in, st_pre, end_pre, preorder, inorder, um);
    }

    TreeNode* constructBT(int st_in, int end_in, int st_pre, int end_pre, vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &um){
        if(st_in>end_in || st_pre>end_pre){
            return nullptr;
        }
        int val = preorder[st_pre];

        TreeNode* root = new TreeNode(val);
        int in_idx = um[val];
        int left_len_in = in_idx-st_in;


        root->left = constructBT(st_in, in_idx-1, st_pre+1, st_pre+(left_len_in), preorder, inorder, um);
        root->right = constructBT(in_idx+1, end_in, st_pre+(left_len_in)+1, end_pre, preorder, inorder, um);

        return root;
    }

};