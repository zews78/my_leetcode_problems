class Solution {
public:
    // int getMaxPt(int i, int j, int k, int n, vector<int>& cardPoints, vector<vector<int>> &dp){
    //     // if(i>j || k==0){
    //     //     return 0;
    //     // }
    //     // if(dp[i][j]!=-1){
    //     //     return dp[i][j];
    //     // }
        
    //     // int left= cardPoints[i] + getMaxPt(i+1, j, k-1, sum, cardPoints, dp);
    //     // int right= cardPoints[j] + getMaxPt(i, j-1, k-1, sum, cardPoints, dp);
    //     // return dp[i][j]= max(left, right);
    //     int dp2[n+1][n+1];
    //     for(int i=0; i<n; i++){
    //         for(int j=n-1; j>=0; j++){
    //             dp[i][j] = max(dp[i-1])
    //         }
    //     }

        
    // }


    int maxScore(vector<int>& cardPoints, int k) {
        // int n = cardPoints.size();
        // int sum =0;
        // int i=0;
        // int j=cardPoints.size()-1;
        // vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        // return getMaxPt(i, j, k, n, cardPoints, dp);

        int i=0;
        int j=0;
        int n = cardPoints.size();
        int window_size = n-k;
        int sum=0;

        int total_sum=0;
        for(int k=0; k<n; k++){
            total_sum+=cardPoints[k];
        }
        for(; j<window_size; j++){
            sum+=cardPoints[j];
        }
        cout<<sum<<endl;
        // j--;
        int min_sum=sum;

        while(j<n){
            sum+=cardPoints[j];
            sum-=cardPoints[i];
            min_sum = min(min_sum, sum);
            // cout<<i<<j<<"-"<<sum<<" "<<min_sum<<" ";
            j++;i++;
        }
        return total_sum-min_sum;
    }
};