class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            int curr = nums[i];
            while(nums[i]<=n && nums[i]>0 && nums[i]!=i+1 && nums[nums[i]-1]!=nums[i]){
                swap(nums[nums[i]-1], nums[i]);
                // cout<<nums[nums[i]-1]<<" ";
            }
        }
        for(int i=0; i<n; i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return n+1;
    }
};