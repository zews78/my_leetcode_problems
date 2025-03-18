class Solution {
public:

    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int j=0;
        int ans=0;
        int store_bits;
        while(j<n){

            while((store_bits & nums[j])!=0){
                store_bits = store_bits ^ nums[i];
                i++;
            }
            store_bits = store_bits | nums[j];
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};