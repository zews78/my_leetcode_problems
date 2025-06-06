class Solution {
public:
    // int solve(int m, int n){
    //     if(m==0 && n==0){
    //         return 1;
    //     }else if(m<0 || n<0){
    //         return 0;
    //     }
    //     else{
    //         return solve(m-1, n) + solve(m, n-1);
    //     }
    // }
    int uniquePaths(int m, int n) {
        // return solve(m-1, n-1);

        int dp[m+1][n+1];
        for(int i=0; i<=m; i++){
            for(int j=0; j<=n; j++){
                if(i==1 && j==1){
                    dp[i][j]=1;
                }else if(i==0 || j==0){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m][n];


    }
};