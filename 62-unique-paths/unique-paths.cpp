class Solution {
public:
    int uniquePaths(int m, int n) {
        // if(m==1 && n==1){
        //     return 1;
        // }
        // if(m<0 || n<0) return 0;

        // return uniquePaths(m-1, n) + uniquePaths(m, n-1);
        int dp[n][m];
        // dp[0][0]=1;
        // for(int i=0; i<n; i++){
        //     dp[i][0] =  1;
        // }
        // for(int j=0; j<m; j++){
        //     dp[0][j] = 1;
        // }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || j==0){
                    dp[i][j] = 1;
                }
                else dp[i][j] = dp[i-1][j]+dp[i][j-1];
                
            }
        }
        return dp[n-1][m-1];
    }
};