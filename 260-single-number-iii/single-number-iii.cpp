class Solution {
public:
    int getLastSetBitIdx(int xorr){
        int idx_cnt=0;
        while(xorr){
            if(xorr & 1){
                break;
            }

            xorr = xorr>>1;
            idx_cnt++;
        }
        return idx_cnt;
    }
    vector<int> singleNumber(vector<int>& nums) {
        int xorr =0;
        vector<int> ans({0, 0});
        int n = nums.size();
        for(int i=0; i<n; i++){
            xorr ^= nums[i];
        }

        int last_set_bit_idx= getLastSetBitIdx(xorr);

        for(int i=0; i<n; i++){
            if(nums[i] & (1<<last_set_bit_idx)){
                ans[0] ^= nums[i];
            }else{
                ans[1] ^= nums[i];
            }
        }
        return ans;

        
    }
};