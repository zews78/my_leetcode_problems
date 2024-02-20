class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int act_sum = n*(n+1)/2;
        int res_sum =0;
        for(int x: nums){
            res_sum+=x;
        }
        return act_sum - res_sum;
    }
};