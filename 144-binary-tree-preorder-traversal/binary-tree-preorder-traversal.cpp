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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;

        TreeNode* curr = root;
        vector<int> res;

        while(curr || !st.empty()){
            if(curr){
                st.push(curr);
                res.push_back(curr->val);
                curr= curr->left;
            }else{
                curr = st.top();
                st.pop();
                curr= curr->right;
            }
        }

        return res;
    }
};