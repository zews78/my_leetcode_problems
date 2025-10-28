class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1; j<n; j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                long long target2 = (long long)target - nums[j]- nums[i];
                int p=j+1, q=n-1;
                while(p<q){
                    int sum = nums[p]+nums[q];
                    if(sum<target2){
                        p++;
                        // while(p<n && nums[p]==nums[p-1]){
                        //     p++;
                        // }
                    }
                    else if(sum>target2){
                        q--;
                        // while(q>=0 && nums[q]==nums[q+1]){
                        //     q--;
                        // }
                    }else{
                        res.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p++;
                        q--;
                        while(p<q && nums[p]==nums[p-1]) p++;
                        while(p<q && nums[q]==nums[q+1]) q--;
                    }
                }
                // while(j<n && nums[j]==nums[j-1]){
                //     j++;
                // }
            }
            // while(i<n && nums[i]==nums[i-1]){
            //     i++;
            // }
        }
        return res;
    }
};