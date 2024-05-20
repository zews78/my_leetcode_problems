class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int len = 1<<n;
        int res_sum =0;
        for(int i=0; i<len; i++){
            int val = i;
            int arr_xorr=0;
            int count =0;
            while(val){
                if(val & 1){
                    arr_xorr ^= nums[count];
                }
                count++;
                val = val>>1;
            }
            res_sum+=arr_xorr;

        }
        return res_sum;
    }
};