class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        for(int i=0; i<nums.size(); i++){
            int act_target = target-nums[i];
            if(um.count(act_target)){
                return {i, um[act_target]};
            }else{
                um[nums[i]]=i;
            }
        }
        return {};
        
    }
};