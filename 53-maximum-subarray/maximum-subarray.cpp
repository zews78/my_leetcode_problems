class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n= nums.size();
        int max_sum;
        int sum =0;
        for(int i=0; i<n; i++){
            int curr = nums[i];
            sum+=curr;
            max_sum = max(max_sum, sum);
            if(sum<0){
                sum =0;
            }
        }
        return max_sum;
    }
};