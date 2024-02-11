class Solution {
public:

    int solve(int n, int p, vector<int> &perfectSq, vector<vector<int>> &dp){
        //bc
        if(n==0){
            return 0;
        }
        if(p==0){
            return INT_MAX;
        }
        if(dp[n][p]!=-1){
            return dp[n][p];
        }

        if(n<perfectSq[p-1]){
            return dp[n][p] = solve(n, p-1, perfectSq,dp);
        }
        else{
            return dp[n][p] = min(solve(n, p-1, perfectSq, dp), 1+solve(n-perfectSq[p-1], p, perfectSq, dp));
        }

    }

    int numSquares(int n) {
        vector<int> perfectSq;
        int i=1;
        while(i*i<=n){
            perfectSq.push_back(i*i);
            i++;
        }
        int p= perfectSq.size();
        vector<vector<int>> dp(n+1, vector<int>(p+1, -1));

        int res = solve(n, p, perfectSq, dp);
        return res;
        // return p;
        // vector<int> dp(n+1, INT_MAX);
        // dp[0]=0;
        // for(int i=1; i<=n; i++){
        //     for(int j=1; j*j<=i; j++){
        //         dp[i] = min(dp[i], dp[i-j*j]+1);
        //     }

        // }
        // return dp[n];

    }
};