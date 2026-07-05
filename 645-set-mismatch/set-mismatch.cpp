class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();

        int i=0;
        while(i<n){
            int curr = nums[i];
            if(curr!=nums[curr-1] && curr-1!=i){
                swap(nums[i], nums[curr-1]);
            }else{
                i++;
            }
        }

        for(int i=0; i<n; i++){
            if(nums[i]!=i+1){
                return {nums[i], i+1};
            }
        }
        return {};
    }
};