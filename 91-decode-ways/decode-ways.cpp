class Solution {
public:
    int solve(int i, string &s, vector<int> &dp){
        if(i>=s.size()){
            return 1;
        }
        int decode2 =10*(s[i]-'0');

        if(i<s.size()-1){
            decode2+=s[i+1]-'0';
        }

        int decode1 = s[i]-'0';
        if(decode1 ==0){
            return 0;
        }

        if(dp[i]!=-1){
            return dp[i];
        }
        else if(i<s.size()-1 && decode2>=1 && decode2<=26){
            return dp[i] = solve(i+2, s, dp) + solve(i+1, s, dp);
        }else{
            return dp[i] = solve(i+1, s, dp);
        }   
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, -1);
        return solve(0 , s, dp);

        // int dp[n+1];

        // dp[0] = 0;

        // for(int i=1; i<=n; i++){

        // }
    }
};