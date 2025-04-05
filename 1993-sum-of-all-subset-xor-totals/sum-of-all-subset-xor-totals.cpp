class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int bitSize = (1<<n) - 1;
        int output=0;
        while(bitSize>=0){
            int val = bitSize;
            cout<<bitSize;
            vector<int> subset;

            int count=0;
            while(val){
                if(val & 1){
                    subset.push_back(nums[count]);
                }
                count++;
                val = val>> 1;
            }
            int xorr=0;
            for(auto x: subset){
                xorr ^= x;
            }
            output+=xorr;
            bitSize--;
        }
        return output;
    }
};