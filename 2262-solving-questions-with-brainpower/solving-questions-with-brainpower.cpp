class Solution {
public:
    long long getMaxPoints(int start, int n, vector<vector<int>>& questions, vector<long long> &dp){
        if(start>=n){
            return 0;
        }
        if(dp[start]!=-1){
            return dp[start];
        }

        long long pick = questions[start][0] + getMaxPoints(start+questions[start][1]+1, n, questions, dp);
        long long not_pick = getMaxPoints(start+1, n, questions, dp);

        return dp[start] = max(pick, not_pick);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n= questions.size();
        vector<long long> dp(n+1, -1);
        return getMaxPoints(0, n, questions, dp);
    }
};