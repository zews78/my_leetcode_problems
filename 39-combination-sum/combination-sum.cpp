class Solution {
public:
    void solve(int n , vector<vector<int>>& combinations, vector<int> temp, vector<int>& candidates, int target){
        if(n==0){
            if(target ==0){
                combinations.push_back(temp);
            }
            return;
        }
        if(candidates[n-1]<=target){
            temp.push_back(candidates[n-1]);
            solve(n, combinations, temp, candidates, target-candidates[n-1]);
            temp.pop_back();
        }
        solve(n-1, combinations, temp, candidates, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n= candidates.size();
        vector<vector<int>> combinations;
        vector<int> temp;
        solve(n, combinations, temp, candidates, target);
        return combinations;
    }
};