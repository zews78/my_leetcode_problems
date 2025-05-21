class Solution {
public:
    bool solve(int i, string s, unordered_set<string> &set, vector<int> &dp){
        if(i==s.size()){
            return true;
        }
        if(dp[i] != -1) return dp[i];

        for(int ind=i; ind<s.size(); ind++){
            if(set.count(s.substr(i, ind-i+1)) && solve(ind+1, s, set, dp)){
                return dp[i]= true;
            }
        }
        return dp[i]= false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        for(auto x: wordDict){
            set.insert(x);
        }
        vector<int> dp(s.size(), -1);
        return solve(0, s, set, dp);
    }
};