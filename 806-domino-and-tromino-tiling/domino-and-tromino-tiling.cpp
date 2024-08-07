class Solution {
public:
    int m = 1e9 +7;
    int numTilings(int n) {
        if(n<=2) return n;
        if(n==3) return 5;
        int dp[n+1];
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;

        for(int i=4; i<=n; i++){
            dp[i]= (2*dp[i-1]%m + dp[i-3]%m)%m;
        }
        return dp[n];
    }
};