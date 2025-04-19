class Solution {
public:
    bool solve(int i, vector<int>& nums, vector<int> &dp){
        if(i>=nums.size()-1){
            return true;
        }
        if(dp[i]!=-1) return dp[i];

        for(int k=i+1; k<=i+nums[i]; k++){
            if(solve(k, nums, dp)){
                return dp[i] = true;
            }
            // return solve(k, nums);
        }
        return dp[i]= false;
    }
    bool canJump(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n+1, -1);
        return solve(0, nums, dp);
    }
};