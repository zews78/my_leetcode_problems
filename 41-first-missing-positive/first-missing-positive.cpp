class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=0;
        int n=nums.size();

        while(i<n){

            if(nums[i] <= 0 || nums[i] > n){  // skip invalid values early
            i++;
            continue;
            }
            int idx = nums[i]-1;

            if(nums[i]!=nums[idx] && i!=idx){
                swap(nums[i], nums[idx]);
            }else{
                i++;
            }
        }
    
        for(int i=0; i<n; i++){
            cout<<nums[i]<<" ";
        }
        for(int i=0; i<n; i++){
            cout<<nums[i]<<" ";
            if(i+1!=nums[i]){
                return i+1;
            }
        }
        return n+1;
    }
};