class Solution {
public:

    // int solve(int n, int p, vector<int> &perfectSq){
    //     //bc
    //     if(n==0){
    //         return 0;
    //     }
    //     if(p==0){
    //         return 0;
    //     }

    //     if(n<perfectSq[p-1]){
    //         return solve(n, p-1, perfectSq);
    //     }
    //     else{
    //         return min(solve(n, p-1, perfectSq), 1+solve(n-perfectSq[p-1], p, perfectSq));
    //     }

    // }

    int numSquares(int n) {
        // vector<int> perfectSq;
        // int i=1;
        // while(i*i<=n){
        //     perfectSq.push_back(i*i);
        //     i++;
        // }
        // int p= perfectSq.size();

        // int res = solve(n, p, perfectSq);
        // return res;
        // return p;
        vector<int> dp(n+1, INT_MAX);
        dp[0]=0;
        for(int i=1; i<=n; i++){
            for(int j=1; j*j<=i; j++){
                dp[i] = min(dp[i], dp[i-j*j]+1);
            }

        }
        return dp[n];

    }
};