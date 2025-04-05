class Solution {
public:
    int solve(int n, vector<int>& nums, int xorr){
        if(n==0){
            return xorr;
        }

        int include = solve(n-1, nums, xorr^nums[n-1]);
        int not_include = solve(n-1, nums, xorr);
        return include + not_include;
    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int xorr =0;
        return solve(n, nums, xorr);
;
    }
};