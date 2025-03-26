class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int start_rem = grid[0][0]%x;
        vector<int> arr;
        for(auto alpha: grid){
            for(auto y: alpha){
                arr.push_back(y);
                if(y%x!=start_rem){
                    return -1;
                }
            }
        }
        sort(arr.begin(), arr.end());

        for(auto x: arr){
            cout<<x<<" ";
        }

        int n = arr.size();
        int median = arr[n/2];
        int output=0;
        for(auto alpha: arr){
            output+= abs((median- alpha)/x);
        }
        return output;
        
    }
};