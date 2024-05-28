class Solution {
public:
    int integerBreak(int n) {
        int W= n;
        int N = n;
        int val[n+1];
        for(int i=0; i<=n; i++){
            val[i]=i;
        }

        int dp[n+2][W+1];
        for(int i=0; i<=N; i++){
            for(int j=0; j<=W; j++){
                if(i==0 || j==0){
                    dp[i][j]= 1;
                }
                else if(val[i-1]>j){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], val[i-1]*dp[i][j-val[i-1]]);
                }
            }
        }
        return dp[N][W];
    }
};