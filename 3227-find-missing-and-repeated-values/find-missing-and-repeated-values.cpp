class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int, int> um;
        int n = grid.size();
        int grid_sum=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                um[grid[i][j]]++;
                grid_sum+=grid[i][j];
            }
        }
        int dup;
        for(auto x: um){
            if(x.second==2) dup = x.first;
        }
        int seq_sum = (n*n*(n*n+1))/2;
        // cout<<seq_sum;
        int miss = seq_sum - (grid_sum-dup);

        return {dup, miss};

    }
};