class Solution {
public:
//without duplicates
    void solve(int n, vector<int>& nums, vector<int> &ans, vector<vector<int>> &res){
        if(n==0){
            res.push_back(ans);
            return;
        }

        ans.push_back(nums[n-1]);
        solve(n-1, nums, ans, res);
        ans.pop_back();
        solve(n-1, nums, ans, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ans;
        int n = nums.size();
        solve(n, nums, ans, res);
        return res;
    }
};