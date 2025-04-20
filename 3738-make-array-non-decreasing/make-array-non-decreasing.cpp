class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n = nums.size();
        int count=1;
        int prev = nums[0];

        for(int i=1; i<n; i++){
            if(prev<=nums[i]){
                prev = nums[i];
                count++;
            }
        }
        return count;

    }
};