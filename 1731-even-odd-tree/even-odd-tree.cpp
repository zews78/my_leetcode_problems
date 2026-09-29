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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        // bool result = true;
        int height =0;
        

        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);

            for(int i=0; i<size; i++){
                auto front = q.front();
                q.pop();
                level[i]=front->val;

                if(height%2==0){
                    if(front->val%2==0){
                        return false;
                    }
                    if(i>0 && level[i-1]>=level[i]){
                        return false;
                    }
                }else{
                    if(front->val%2!=0){
                        return false;
                    }
                    if(i>0 && level[i-1]<=level[i]){
                        return false;
                    }
                }
                

                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            height++;
        }

        return true;
    }
};