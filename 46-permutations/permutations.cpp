class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr =nums;
        vector<vector<int>> res;
        solve(0, arr, res, nums);
        return res;
    }

    void solve(int i, vector<int> arr, vector<vector<int>> &res, vector<int> &nums){
        if(i==arr.size()-1){
            res.push_back(arr);
            return;
        }

        for(int ind=i; ind<nums.size(); ind++){
            swap(arr[i], arr[ind]);
            solve(i+1, arr, res, nums);
            swap(arr[i], arr[ind]);
        }
    }
};