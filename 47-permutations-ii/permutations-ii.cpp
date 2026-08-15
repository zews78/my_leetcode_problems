class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        vector<bool> visited(N, false);
        vector<vector<int>> ans;
        vector<int> arr;
        solve(N, nums, arr, visited, ans);
        return ans;
    }

    void solve(int N , vector<int>& nums, vector<int> &arr, vector<bool> &visited, vector<vector<int>> &ans){
        if(arr.size()==N){
            ans.push_back(arr);
        }

        for(int i=0; i<N; i++){
            if(i>0 && nums[i]==nums[i-1] && visited[i-1]){
                continue;
            }
            if(!visited[i]){
                visited[i]=true;
                arr.push_back(nums[i]);
                solve(N, nums, arr, visited, ans);
                visited[i]=false;
                arr.pop_back();
            }
    
        }
    }
};