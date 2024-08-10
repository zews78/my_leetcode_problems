class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(n==0 || m==0) return 0;
        if(obstacleGrid[0][0]==1 || obstacleGrid[n-1][m-1]==1) return 0;
        int dp[n][m];
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<n; i++){
            if(obstacleGrid[i][0]==0){
                dp[i][0] =1;
            }
            else{
                break;
            }
        }
        for(int j=0; j<m; j++){
            if(obstacleGrid[0][j]==0){
                dp[0][j]= 1;
            }
            else{
                break;
            }
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                }
                else dp[i][j] =  dp[i-1][j] + dp[i][j-1];
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        return dp[n-1][m-1];
    }
};