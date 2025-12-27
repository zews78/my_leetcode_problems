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
    vector<int> rightSideView(TreeNode* root) {
        // code here
        if(!root) return {};
        // vector<vector<int>> level;
        vector<int> res;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty()){
            int q_len = q.size();
            for(int i=0; i<q_len; i++){
                TreeNode* front = q.front();
                q.pop();
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
                if(i==q_len-1){
                    res.push_back(front->val);
                }
            }
        }
        
        return res;
        
    }

};