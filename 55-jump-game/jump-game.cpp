class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n= nums.size();
        // if(n<=1){
        //     return true;
        // }
        // if(nums[0]==0){
        //     return false;
        // }
        int max_reach_ind = 0;
        for(int i=0; i<n-1; i++){
            max_reach_ind = max(max_reach_ind, i+nums[i]);
            if(nums[i]==0 && max_reach_ind<=i){
                return false;
            }
        }
        if(max_reach_ind>=n-1) return true;
        return false;
    }
};