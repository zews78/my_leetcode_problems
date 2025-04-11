class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        int n =nums.size();
        for(int i=0; i<n-2; i++){
            int val1= nums[i];
            
            int l = i+1;
            int r = n-1;
            int target2 = 0-val1;
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }

            while(l<r){
                if(nums[l]+nums[r] == target2){
                    output.push_back({val1, nums[l], nums[r]});
                    while(l<r && nums[l]==nums[l+1]){
                        l++;
                    }
                    while(l<r && nums[r]==nums[r-1]){
                        r--;
                    }
                    l++;
                    r--;


                }
                else if(nums[l]+nums[r] > target2){
                    r--;
                }else{
                    l++;
                }
            }

        }
        return output;
    }
};