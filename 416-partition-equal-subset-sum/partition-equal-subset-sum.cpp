class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //cal N, W
        int N = nums.size();
        int W = 0;
        for(int i=0; i<N; i++){
            W += nums[i];
        }
        if(W & 1){
            return false;
        }
        W=W/2;
        
        //initialize
        int dp[N+1][W+1];
        // for(int j=0; j<=W; j++){
        //     dp[0][j]=false;
        // }
        // for(int i=0; i<=N; i++){
        //     dp[i][0]=true;
        // }
        
        //decision tree
        for(int i=0; i<=N; i++){
            for(int j=0; j<=W; j++){
                if(j==0){
                    dp[i][j]=1;
                }
                else if(i==0){
                    dp[i][j]=0;
                }

                else if(nums[i-1]>j){
                    dp[i][j]= dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[N][W];
        for(int i=0; i<=N; i++){
            for(int j=0; j<=W; j++){
                cout<<dp[i][j]<<" ";
            }cout<<endl;
        }
    }

};