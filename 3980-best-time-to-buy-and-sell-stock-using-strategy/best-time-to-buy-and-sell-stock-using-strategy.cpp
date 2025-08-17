typedef long long ll;

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = strategy.size();

        vector<long long> prefix(n+1, 0);
        vector<long long> prefix_price_sum(n+1, 0);
        long long indi_pr_sum =0;
        ll price_sum_val =0;
        int i;
        for(i=0; i<n; i++){
            prefix_price_sum[i] = (price_sum_val);
            prefix[i] = (indi_pr_sum);
            price_sum_val+=prices[i];
            indi_pr_sum += (ll)strategy[i]*prices[i];
        }
        prefix_price_sum[i] = (price_sum_val);
        prefix[i] = (indi_pr_sum);

        long long base_val = prefix[n];
        // for(int i=0; i<=n; i++){
        //     cout<<prefix[i]<<" ";
        // }cout<<endl;
        // for(int i=0; i<=n; i++){
        //     cout<<prefix_price_sum[i]<<" ";
        // }cout<<endl;

        // long long first_win =0;
        // for(int i=0; i<k/2; i++){
        //     first_win+= -strategy[i]*prices[i];
        // }
        // for(int i=k/2; i<k; i++){
        //     first_win+= prices[i] - (strategy[i]*prices[i]);
        // }

        long long maxi =base_val;

        for(int i=k; i<=n; i++){
            ll win_val = base_val - (prefix[i]-prefix[i-k]) + (prefix_price_sum[i]-prefix_price_sum[i-(k/2)]);
            // cout<<win_val<<" ";
            maxi = max(maxi, win_val);
        }
        return maxi;

        
    }
};