class Solution {
public:
    // bool checkPossibleCapacity(int n, vector<int> &nums, int k, int mid, int maxi){
    //     if(k==0){
    //         if(maxi>=mid){
    //             return true;
    //         }
    //     }
    //     if(k<0){

    //     }

    //     if(n<=0){
    //         return false;
    //     }
        
    //     int getMax = max(maxi, nums[n-1]);

    //     bool include = checkPossibleCapacity(n-2, nums, k-1, mid, getMax);
    //     bool not_include = checkPossibleCapacity(n-1, nums, k, mid, maxi);
    //     return include || not_include;
    // }

    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();

        int i=1;
        int j;
        int ans;
        for(auto x: nums){
            // i = min(i, x);
            j = max(j, x);
        }
        // cout<< checkPossibleCapacity(n, nums, k, 5, 0);
        while(i<=j){
            int mid = i + (j-i)/2;
            int checkPossibleVals=0;
            for(int i=0; i<n; i++){
                if(nums[i]<=mid){
                    checkPossibleVals++;
                    i++;
                }
            }
            if(checkPossibleVals>= k){
                ans = mid;
                j= mid-1;
            }else{
                i=mid+1;
            }

        }
        return ans;

    }
};