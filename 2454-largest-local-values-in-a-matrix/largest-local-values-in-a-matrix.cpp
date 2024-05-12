class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> result;

        int n = grid.size();
        int m = grid[0].size();
        // cout<<n<<" "<<m<<endl;
        for(int i=1; i<n-1; i++){
            vector<int> sumVals;
            for(int j=1; j<m-1; j++){
                int max_val=INT_MIN;
                for(int p=i-1;p<=i+1;p++){
                    for(int q=j-1; q<=j+1; q++){
                        max_val = max(grid[p][q], max_val);
                        // cout<<grid[p][q];
                    }
                }
                sumVals.push_back(max_val);
            }
            result.push_back(sumVals);
        }
        return result;
    }
};