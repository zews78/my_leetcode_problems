class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 1e9));
        // int dp[n+1][m+1];
        dp[n][m-1]=1;
        dp[n-1][m]=1;

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int minVal = min(dp[i+1][j], dp[i][j+1])-dungeon[i][j];
                if(minVal<=0){
                    dp[i][j]=1;
                }else{
                    dp[i][j] = minVal;
                }

            }
        }
        return dp[0][0];
    }
};