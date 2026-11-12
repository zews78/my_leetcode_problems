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
    TreeNode* constructTree(int st_in,int end_in,int st_pre,int end_pre,vector<int>& preorder,vector<int>& inorder, unordered_map<int, int> &um){
        //base case
        if(st_in > end_in || st_pre > end_pre){
            return nullptr;
        }

        int in_idx = um[preorder[st_pre]];
        int len_in = in_idx-st_in;

        TreeNode* root = new TreeNode(preorder[st_pre]);

        root->left = constructTree(st_in, in_idx-1, st_pre+1, st_pre+(len_in), preorder, inorder, um);
        root->right = constructTree(in_idx+1, end_in, st_pre+len_in+1, end_pre, preorder, inorder, um);


        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> um;

        for(int i=0; i<inorder.size(); i++){
            um[inorder[i]]=i;
        }

        int st_in=0;
        int end_in=inorder.size()-1;

        int st_pre=0;
        int end_pre = preorder.size()-1;

        return constructTree(st_in, end_in, st_pre, end_pre, preorder, inorder, um);
    }
};