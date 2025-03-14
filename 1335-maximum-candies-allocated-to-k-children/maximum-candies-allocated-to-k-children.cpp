class Solution {
public:
    bool check_feasible_dist(vector<int> temp_candies, long long temp_k, int max_number, int n){
        if(max_number==0) return false;
        for(int i=0; i<n; i++){
            temp_k -= temp_candies[i]/max_number;
        }
        if(temp_k <=0){
            return true;
        }
        return false;
            // int i=0;
            // int cont_bounce=0;
            // while(temp_k){
            //     if(temp_candies[i%n]-max_number>=0){
            //         temp_candies[i%n]-= max_number;
            //         temp_k--;
            //         cont_bounce=0;
            //     }else{
            //         cont_bounce++;
            //     }
            //     i++;
            //     //breaking statement
            //     if(cont_bounce==n){
            //         return false;
            //     }
            // }
            // return true;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        long long total_sum=0;
        int i=1;
        int j=candies[0];
        for(auto x: candies){
            j = max(x, j);
            total_sum+=x;
        }
        if(total_sum<k){
            return 0;
        }
        // if(total_sum==k){
        //     return 1;
        // }
        // cout<<j<<endl;
        int ans = 0;
        while(i<=j){
            int mid = i +(j-i)/2;
            if(check_feasible_dist(candies, k, mid, n)){
                ans = mid;
                i = mid+1;
            }else{
                j= mid-1;
            }
        }
        // cout<<check_feasible_dist(candies, k, 4, n);
        return ans;

        // while(true){
        //     if(!check_feasible_dist(candies, k, max_number, n)){
        //         return max_number-1;
        //     }else{
        //         max_number++;
        //     }
        //     cout<<max_number<<" ";

        //     //breaking statement
        // }
        // return max_number-1;
    }
};