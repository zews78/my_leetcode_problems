class Solution {
public:
    int getSubsequences(int i, int prevIndex, vector<int>& nums, vector<vector<int>>& dp){
        if(i == nums.size()) return 0;

        if(dp[i][prevIndex + 1] != -1) return dp[i][prevIndex + 1];

        int take = 0;
        if(prevIndex == -1 || nums[i] > nums[prevIndex]){
            take = 1 + getSubsequences(i + 1, i, nums, dp);
        }

        int notTake = getSubsequences(i + 1, prevIndex, nums, dp);

        return dp[i][prevIndex + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // prevIndex goes from -1 to n-1 => dp[i][prev+1]
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return getSubsequences(0, -1, nums, dp);
    }
};
