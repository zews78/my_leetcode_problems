class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int n = nums.size();
        int p =0, m =0;
        for(auto x: nums){
            if(x>0){
                p++;
            }else{
                m++;
            }
        }

        // if(p%2!=0 || m%2!=0){
        //     return false;
        // }

        int count_ones = 0;
        int count_minus_ones = 0;
        vector<int> nums_copy = nums;
        for(int i=0; i<n-1; i++){
            if(nums[i]==-1){
                nums[i] *= -1;
                nums[i+1] *= -1;
                count_minus_ones++;
            }
        }

        for(int i=0; i<n-1; i++){
            if(nums_copy[i]==1){
                nums_copy[i] *= -1;
                nums_copy[i+1] *= -1;
                count_ones++;
            }
        }


        if((p%2==0 && count_ones<=k) || (m%2==0 && count_minus_ones<=k)){
            return true;
        }
        return false;
    }
};