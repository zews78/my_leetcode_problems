class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int st=0;
        int end=n-1;
        int ans=0;

        while(st<end){
            int mid=st+(end-st)/2;

            if(nums[mid+1]-nums[mid]>=0){
                // ans = mid+1;
                st = mid+1;
            }else{
                // ans = mid;
                end=mid; //cause mid is also a valid peak
            }
        }

        return end;


    }
};