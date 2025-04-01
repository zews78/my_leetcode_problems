class Solution {
public:
    // long long getMaxPoints(int start, int n, vector<vector<int>>& questions, vector<long long> &dp){
    //     if(start>=n){
    //         return 0;
    //     }
    //     if(dp[start]!=-1){
    //         return dp[start];
    //     }

    //     long long pick = questions[start][0] + getMaxPoints(start+questions[start][1]+1, n, questions, dp);
    //     long long not_pick = getMaxPoints(start+1, n, questions, dp);

    //     return dp[start] = max(pick, not_pick);
    // }

    long long mostPoints(vector<vector<int>>& questions) {
        int n= questions.size();
        // vector<long long> dp(n+1, -1);
        // return getMaxPoints(0, n, questions, dp);
        // vector<int> dp(n, -1);
        // long long dp[n+1e5+1];
        // vector<long long> dp(n+1e5+1, 0);
        // for(int i=n+1e5+1; i>=n; i++){
        //     dp[i]=0;
        // }
        // vector<long long> dp(n + 1, 0);
        long long dp[n+1];
        dp[n] = 0;
        for(int i=n-1; i>=0; i--){
            long long not_include = dp[i+1];

            long long include = questions[i][0];
            if(i+questions[i][1]+1 <=n){
                include += dp[i+questions[i][1]+1];
            }

            dp[i] = max(include, not_include);
            
        }
        return dp[0];



    // int n = questions.size();
    // vector<long long> dp(n + 1, 0);
    
    // // Start from the end and work backwards
    // for (int i = n - 1; i >= 0; i--) {
    //     int points = questions[i][0];
    //     int jump = questions[i][1];
        
    //     // Next position after taking current question
    //     int next = i + jump + 1;
        
    //     // If we're still within bounds after the jump
    //     long long pickCurrent = points + (next < n + 1 ? dp[next] : 0);
        
    //     // Skip current question
    //     long long skipCurrent = dp[i + 1];
        
    //     // Maximum points at this position
    //     dp[i] = max(pickCurrent, skipCurrent);
    // }
    
    // return dp[0];

    }


};