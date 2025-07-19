class Solution {
public:
    int solve(int n, int m, string &word1, string &word2, vector<vector<int>> &dp){
        if(n==0 && m==0){
            return 0;
        }
        if(n==0 || m==0){
            return abs(n-m);
        }

        if(dp[n-1][m-1]!=-1){
            return dp[n-1][m-1];
        }

        if(word1[n-1]==word2[m-1]){
            return dp[n-1][m-1] = solve(n-1, m-1, word1, word2, dp);
        }else{
            return dp[n-1][m-1] = min(1+solve(n-1, m, word1, word2, dp), 1+solve(n, m-1, word1, word2, dp));
        }
    }
    int minDistance(string word1, string word2) {
        int n= word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(n, m, word1, word2, dp);
    }
};