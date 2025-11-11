class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<int> subset;
        vector<vector<int>> all_subsets;
        solve(0, n, candidates, subset, all_subsets, target);
        return all_subsets;
    }
    void solve(int i, int n, vector<int> &nums, vector<int> subset, vector<vector<int>> &all_subsets, int target){
        if(target<=0){
            if(target==0) all_subsets.push_back(subset);
            return;
        }

        for(int ind=i; ind<n; ind++){
            //dup
            if(ind>i && nums[ind]==nums[ind-1]){
                continue;
            }

            subset.push_back(nums[ind]);
            target -= nums[ind];
            solve(ind+1, n, nums, subset, all_subsets, target);
            subset.pop_back();
            target+= nums[ind];
            // solve(ind+1, n, nums, subset, all_subsets, target);
        }
    }
};