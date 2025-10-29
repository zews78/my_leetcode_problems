class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        int sum =0;
        int count =0;

        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            if(sum==k){
                count++;
            }
            if(um.count(sum-k)){
                count+=um[sum-k];
            }
            um[sum]++;
        }
        return count;
    }
};