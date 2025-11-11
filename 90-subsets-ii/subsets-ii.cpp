class Solution {
public:
    void solve(int i, int n, vector<int> &nums, vector<int> subset, vector<vector<int>> &all_subsets){
        all_subsets.push_back(subset);
        
        for(int ind = i; ind<n; ind++){
            if(ind>i && nums[ind]==nums[ind-1]){
                continue;
            }

            subset.push_back(nums[ind]);
            solve(ind+1, n, nums, subset, all_subsets);
            subset.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int> subset;
        sort(nums.begin(), nums.end());
        vector<vector<int>> all_subsets;
        solve(0, n, nums, subset, all_subsets);
        return all_subsets;
    }
};