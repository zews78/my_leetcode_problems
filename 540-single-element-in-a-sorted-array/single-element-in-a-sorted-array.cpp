class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int ans=n-1;

        if(n==1){
            return nums[0];
        }

        int st=1;
        int end=n-1;

        while(st<=end){
            int mid=st+(end-st)/2;
            if(mid%2==0){
                mid++;
            }

            if(nums[mid]==nums[mid-1]){
                st=mid+2;
            }else{
                ans=mid-1;
                end=mid-2;
            }
        }

        return nums[ans];
    }
};