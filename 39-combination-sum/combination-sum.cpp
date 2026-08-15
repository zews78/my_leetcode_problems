class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int N=candidates.size();
        vector<int> arr;
        vector<vector<int>> ans;

        solve(N, arr, ans, candidates, target);
        return ans;
    }

    void solve(int N, vector<int> &arr, vector<vector<int>> &ans, vector<int>& candidates, int target){
        if(N==0){
            if(target == 0){
                ans.push_back(arr);
            }
            return;
        }

        if(candidates[N-1]<=target){
            arr.push_back(candidates[N-1]);
            solve(N, arr, ans, candidates, target-candidates[N-1]);
            arr.pop_back();
        }
        solve(N-1, arr, ans, candidates, target);
    }
};