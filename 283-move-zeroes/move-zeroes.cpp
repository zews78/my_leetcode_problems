class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i =0, j=0;
        int n= nums.size();
        while(j<n){
            int l = nums[i];
            int r = nums[j];
            if(nums[i]==0 && nums[j]!=0){
                swap(nums[i], nums[j]);
                i++; j++;
            }else if(nums[i]!=0 && nums[j]==0){
                i++;
            }else if(nums[i]!=0 && nums[j]!=0){
                i++; j++;
            }else{
                j++;
            }
        }
    }
};