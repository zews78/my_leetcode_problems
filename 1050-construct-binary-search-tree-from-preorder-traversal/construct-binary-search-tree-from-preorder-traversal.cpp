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
    vector<int> next_greater_ele;
    void cal_next_greater_ele(vector<int>& preorder){
        int n= preorder.size();
        stack<pair<int, int>> st;
        st.push({INT_MAX, n});

        for(int i=n-1; i>=0; i--){
            int curr = preorder[i];
            while(!st.empty() && st.top().first<curr){
                st.pop();
            }
            next_greater_ele[i] = st.top().second;
            st.push({curr, i});
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int st = 0;
        int end = preorder.size()-1;
        next_greater_ele.resize(preorder.size());
        cal_next_greater_ele(preorder);
        return solve(st, end, preorder);
    }
    // int getNGE(int st, int end, vector<int> &preorder){
    //     int val = preorder[st];
    //     st++;
    //     while(st<=end && val>preorder[st]){
    //         st++;
    //     }

    //     return st;
    // }
    TreeNode* solve(int st, int end, vector<int>& preorder){
        if(st>end){
            return nullptr;
        }
        int val = preorder[st];
        TreeNode* node = new TreeNode(val);

        int nge = next_greater_ele[st];
        // cout<<nge<<endl;

        node->left = solve(st+1, nge-1, preorder);
        node->right = solve(nge, end, preorder);

        return node;
    }
};