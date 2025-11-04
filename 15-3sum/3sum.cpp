class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n=nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int two_sum = -1*nums[i];
            int st=i+1;
            int end=n-1;

            while(st<end){
                int curr_sum= nums[st]+nums[end];
                if(curr_sum== two_sum){
                    res.push_back({nums[i], nums[st], nums[end]});
                    while(st<end && nums[st]==nums[st+1]){
                        st++;
                    }
                    while(st<end && nums[end]==nums[end-1]){
                        end--;
                    }
                    st++;end--;
                }
                else if(curr_sum<two_sum){
                    st++;
                }else{
                    end--;
                }
            }
        }
        return res;
    }
};