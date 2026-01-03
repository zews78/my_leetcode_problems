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
    int widthOfBinaryTree(TreeNode* root) {
        long long int res = INT_MIN;
        if(!root) return 0;

        queue<pair<TreeNode*, long long int>> q;
        
        q.push({root, 0});

        while(!q.empty()){
            
            long long int high = q.front().second;
            long long int low = q.back().second;
            res = max(res, (high-low)+1);

            int q_size = q.size();
            for(int i=0; i<q_size; i++){
                auto front = q.front();
                q.pop();

                long long int idx = front.second - low;
                TreeNode* node = front.first;

                if(node->right){
                    q.push({node->right, (long long int)2*idx+2});
                }
                if(node->left){
                    q.push({node->left, (long long int)2*idx+1});
                }

            }

        }
        return res;
    }
};