class Solution {
public:
    // int solve(int n, vector<int>& nums){
    //     if(n<=0){
    //         return 0;
    //     }

    //     return max(nums[n-1]+solve(n-2, nums), solve(n-1, nums));
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();
        // return solve(n, nums);

        int dp[n+1];
        dp[0]=0;

        for(int i=1; i<=n; i++){
            if(i==1){
                dp[i] = nums[i-1];
            }else{
                dp[i] = max(nums[i-1]+dp[i-2], dp[i-1]);
            }
        }
        return dp[n];

    }
};