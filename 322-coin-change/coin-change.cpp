class Solution {
public:
    // int solve(int n, int amount, vector<int>& coins){
    //     // if(n==0 )
    //     if(amount ==0){
    //         return 0;
    //     }
    //     if(n==0){
    //         return 1e5;
    //     }
        
    //     else if(amount<coins[n-1]){
    //         return solve(n-1, amount, coins);
    //     }else{
    //         return min(solve(n-1, amount, coins), 1+solve(n, amount-coins[n-1], coins));
    //     }
    // }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // return (solve(n, amount, coins)==1e5)?-1:solve(n, amount, coins);

        // vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        int dp[n+1][amount+1];

        for(int i=0; i<=n; i++){
            for(int j=0; j<=amount; j++){
                if(i==0){
                    dp[i][j]=1e5;
                }
                else if(j==0){
                    dp[i][j]=0;
                }

                else if(j<coins[i-1]){
                    dp[i][j]= dp[i-1][j];
                }else{
                    dp[i][j] = min(dp[i-1][j], 1+dp[i][j-coins[i-1]]);
                }
            }
        }
        return (dp[n][amount] > 1e4)? -1: dp[n][amount];

    }
};