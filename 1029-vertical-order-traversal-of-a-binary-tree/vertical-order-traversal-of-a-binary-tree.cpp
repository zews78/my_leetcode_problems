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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //col row root
        if(!root) return {{}};
        vector<tuple<int, int, int>> res;
        dfs(0, 0, root, res);

        sort(res.begin(), res.end());
        vector<vector<int>> result;
        int prev_col = INT_MIN;

        for(auto [col, row, node_val]: res){
            // cout<<row<<
            if(col!=prev_col){
                result.push_back({});
                prev_col = col;
            }
            result.back().push_back(node_val);
        }

        return result;
    }

    void dfs(int col, int row, TreeNode* root, vector<tuple<int, int, int>> &res){
        res.push_back({col, row, root->val});
        if(root->left){
            dfs(col-1, row+1, root->left, res);
        }
        if(root->right){
            dfs(col+1, row+1, root->right, res);
        }
    }
};