class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long m = n*n;
        long long ac_sum=0;
        long long ac_sq_sum =0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                ac_sum+=grid[i][j];
                ac_sq_sum+=grid[i][j]*grid[i][j];
            }
        }
        // long long sum = (m*(m+1))/2;
        // long long int sq_sum = (m*(m+1)*(2*m+1))/6;

        long long sq_diff = (m*(m+1)*(2*m+1))/6 - ac_sq_sum;
        long long sum_diff = (m*(m+1))/2- ac_sum;

        int miss = ((sq_diff/sum_diff)+sum_diff)/2;
        int dup = ((sq_diff/sum_diff)-sum_diff)/2;

        // unordered_map<int, int> um;
        // int n = grid.size();
        // int grid_sum=0;
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         um[grid[i][j]]++;
        //         grid_sum+=grid[i][j];
        //     }
        // }
        // int dup;
        // for(auto x: um){
        //     if(x.second==2) dup = x.first;
        // }
        // int seq_sum = (n*n*(n*n+1))/2;
        // // cout<<seq_sum;
        // int miss = seq_sum - (grid_sum-dup);

        return {dup, miss};

    }
};