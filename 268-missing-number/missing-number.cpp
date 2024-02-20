class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<bool> med(nums.size()+1, 0);
        for(int x: nums){
            med[x]=1;
        }
        for(int i=0; i<med.size(); i++){
            if(med[i]==0){
                return i;
            }
        }
        return 0;
    }
};