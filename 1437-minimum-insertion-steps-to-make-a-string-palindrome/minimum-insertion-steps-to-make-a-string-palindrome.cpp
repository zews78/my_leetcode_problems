class Solution {
public:
    int minInsertions(string s) {
                int m = s.size();
        int n = m;
        string s2 =s;
        reverse(s.begin(), s.end());
        // vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        // return solve(n, m, text1, text2, dp);

        int dp[n+1][m+1];
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
                else if(s[i-1] == s2[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1];
                }
                else{
                    dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        int lps = dp[n][m];
        return n- lps;
    }
};