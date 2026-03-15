class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i=0;
        int n=nums.size();

        while(i<n){
            int curr = nums[i];

            if(curr<n && nums[i]!=i){
                swap(nums[i], nums[curr]);
            }else{
                i++;
            }
        }

        for(int i=0; i<n; i++){
            if(nums[i]!=i){
                return i;
            }
        }
        return n;
    }
};