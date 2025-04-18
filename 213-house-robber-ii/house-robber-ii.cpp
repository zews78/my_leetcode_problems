class Solution {
public:
    // int solve(int n, bool startPick, vector<int> &nums){
    //     if(startPick && n<=1){
    //         return 0;
    //     }
    //     else if(!startPick && n<=0){
    //         return 0;
    //     }

    //     else if(n==nums.size()){
    //         return max(nums[n-1]+solve(n-2, true, nums), solve(n-1, startPick, nums));
    //     }else{
    //         return max(nums[n-1]+solve(n-2, startPick, nums), solve(n-1, startPick, nums));
    //     }
    // }

    // int solve(int start, int end, vector<int>& nums){
    //     if(start>end){
    //         return 0;
    //     }

    //     return max(nums[start]+solve(start+2, end, nums), solve(start+1, end, nums));
    // }

    int solve(int start, int end, vector<int> &nums){
        int n = end - start+1;
        int dp[n+1];
        dp[0] =0;
        dp[1] = nums[start];
        for(int i=2; i<=n; i++){
            if(i<start){
                dp[i]=0;
            }

            dp[i] = max(nums[i+start-1]+dp[i-2], dp[i-1]);
        }
        return dp[n];

    }

    int rob(vector<int>& nums) {
        int n =nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        return max(solve(0, n-2, nums), solve(1, n-1, nums));
 
    }
};