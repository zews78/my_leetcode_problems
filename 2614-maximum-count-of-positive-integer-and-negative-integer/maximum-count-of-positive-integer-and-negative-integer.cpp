class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int first_pos_occ;
        int last_neg_occ;
        
        int start= 0;
        int end =n-1;

        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid]>0){
                first_pos_occ = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        // cout<<start<<endl;
        start= 0;
        end =n-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid]<0){
                last_neg_occ = mid;
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        // cout<<end<<endl;
        cout<<last_neg_occ<<","<<first_pos_occ<<" ";

        if(nums[0]==0 && nums[n-1]==0){
            return 0;
        }

        if(nums[0]>=0){
            return n-first_pos_occ;
        }
        if(nums[n-1]<=0){
            return last_neg_occ+1;
        }

        return max(last_neg_occ+1, n-first_pos_occ);
    }
};