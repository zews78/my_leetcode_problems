class Solution {
public:
    bool checkIncreasing(vector<int> nums){
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]>nums[i+1]){
                return false;
            }
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int count=0;
        while(!checkIncreasing(nums)){
            int n = nums.size();
            int SmallestPair = -1;
            int smallest_val= INT_MAX;
            for(int i=0; i<n-1; i++){
                if(nums[i]+nums[i+1]<smallest_val){
                    smallest_val = nums[i]+nums[i+1];
                    SmallestPair=i;
                }
            }
            vector<int> temp;
            for(int i=0; i<n; i++){
                if(i==SmallestPair){
                    temp.push_back(nums[i]+nums[i+1]);
                    i++;
                }else{
                    temp.push_back(nums[i]);
                }
            }
            nums = temp;
            count++;
        }   
        return count;
    }
};