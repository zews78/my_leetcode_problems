class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int prev = -1;
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(0, prev, nums, dp);
    }
    int solve(int i, int prev, vector<int>& nums, vector<vector<int>>& dp){
        if(i==nums.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }

        if(prev==-1 || (prev!=-1 && nums[i]>nums[prev])){
            return dp[i][prev+1] = max(1+solve(i+1, i, nums, dp), solve(i+1, prev, nums,dp));
        }else{
            return dp[i][prev+1] = solve(i+1, prev, nums, dp);
        }
    }
};