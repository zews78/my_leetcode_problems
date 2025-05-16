class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minStart =1;
        int sum =nums[0];
        minStart = min(minStart, sum);
        for(int i=1; i<nums.size(); i++){
            sum += nums[i];
            minStart = min(minStart, sum);
        }
        // minStart = min(minStart, sum);
        if(minStart==1){
            return 1;
        }else{
            return abs(minStart)+1;
        }
    }
};