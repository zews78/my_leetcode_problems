class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();

        int st=0;
        int end=n-1;
        // int v0 = nums[0]; not needed

        while(st<=end){
            int mid = st+(end-st)/2;

            if(nums[mid]==target){
                // cout<<mid<<endl;
                return true;
            }

            if(nums[st]==nums[mid] && nums[end]==nums[mid]){
                st++;
                end--;
                continue;
            }
            
            //left half is sorted
            if(nums[st]<=nums[mid]){
                //bs(st, mid)
                if(target>=nums[st] && target<nums[mid]){
                    end = mid-1;
                }else{
                    st = mid+1;
                }
                
            //right half is sorted
            }else{
                if(target>nums[mid] && target<=nums[end]){
                    st = mid+1;
                }else{
                    end = mid-1;
                }
            }

        }
        return false;
    }
};