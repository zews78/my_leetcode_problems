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
    void reverseVals(vector<TreeNode*> &level){
        int st=0;
        int e=level.size()-1;
        while(st<=e){
            int temp=level[st]->val;
            level[st]->val = level[e]->val;
            level[e]->val = temp;
            st++; e--;
        }
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;

        q.push(root);
        bool flag=true;

        

        while(!q.empty()){
            int size = q.size();
            vector<TreeNode*> level(size);
            for(int i=0; i<size; i++){
                auto front = q.front();
                q.pop();
                level[i]=front;
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            if(!flag) reverseVals(level);

            flag=!flag;
        }

        return root;
    }
};