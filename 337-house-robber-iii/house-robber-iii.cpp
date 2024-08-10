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
    unordered_map<TreeNode*, int> memo;
    int rob(TreeNode* root) {
        // tabuation approach
        



        //bfs
        // bool flag= true;
        // vector<int> arr;
        // queue<TreeNode*> q;
        // q.push(root);
        //     // int odd_sum = 0;
        //     // int even_sum =0;
        // while(!q.empty()){
        //     int size = q.size();
        //     int level =0;
        //     for(int i=0; i<size; i++){
        //         TreeNode* top = q.front();
        //         if(top->left){
        //             q.push(top->left);
        //         }
        //         if(top->right){
        //             q.push(top->right);
        //         }
        //         // if(flag){
        //         //     odd_sum+=top->val;
        //         // }else{
        //         //     even_sum+=top->val;
        //         // }
        //         level+=top->val;
        //         q.pop();
        //     }
        //     arr.push_back(level);
        //     // cout<<level<<" ";
        //     // flag =!flag;
        // }
        // int n = arr.size();
        // int dp[n];
        // // dp[0]= 0;
        // dp[0]= arr[0];
        // for(int i=1; i<n; i++){
        //     int include = arr[i];
        //     if(i>1){
        //         include += dp[i-2];
        //     }
        //     int not_include = dp[i-1];
        //     dp[i] = max(include, not_include);
        // }
        // return dp[n-1];

        // return max(odd_sum, even_sum);

        //dfs approach
        if(!root){
            return 0;
        }
        
        if(memo[root]) return memo[root];

        //not include
        int not_include=0;
        if(root->left){
            not_include += rob(root->left);
        }
        if(root->right){
            not_include += rob(root->right);
        }
        int include=root->val;
        if(root->left){
            if(root->left->left){
                include+=rob(root->left->left);
            }
            if(root->left->right){
                include+=rob(root->left->right);
            }
        }

        if(root->right){
            if(root->right->left){
                include+=rob(root->right->left);
            }
            if(root->right->right){
                include+=rob(root->right->right);
            }
        }

        // cout<<include<<" "<<not_include<<endl;
        return memo[root] = max(include, not_include);

    }
};