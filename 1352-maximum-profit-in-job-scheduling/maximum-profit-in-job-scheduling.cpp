class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<tuple<int, int, int>> jobs(n);

        // Combine job data
        for (int i = 0; i < n; ++i) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }

        // Sort jobs by startTime
        sort(jobs.begin(), jobs.end());

        // Extract sorted job info back into vectors
        for (int i = 0; i < n; ++i) {
            tie(startTime[i], endTime[i], profit[i]) = jobs[i];
        }
        // vector<vector<int>>dp(n+1, vector<int>(endTime[n-1]+1, -1));
          vector<int> dp(n, -1);

        return solve(0, startTime, endTime, profit, dp);
    }

    int solve(int i, vector<int>& startTime, vector<int>& endTime, vector<int>& profit, vector<int> &dp) {
        if (i == profit.size()) return 0;

        
        if(dp[i]!=-1){
            return dp[i];
        }

        // int pick = 0;
        // if (startTime[i] >= lastEndTime) {
        // }
        int next = lower_bound(startTime.begin(), startTime.end(), endTime[i])-  startTime.begin();

        int pick = profit[i] + solve(next, startTime, endTime, profit, dp);
        int not_pick = solve(i + 1, startTime, endTime, profit, dp);

        return dp[i] = max(pick, not_pick);
    }
};
