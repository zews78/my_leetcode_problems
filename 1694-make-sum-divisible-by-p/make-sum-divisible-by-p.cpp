class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long total_sum =0;
        for(auto x: nums){
            total_sum+=x;
        }
        if(total_sum<p) return -1;

        int rem = total_sum%p;
        if(rem==0) return 0;

        unordered_map<long long,int> um;
        um[0] = -1;
        long long prefix=0;
        int min_len = INT_MAX;

        for(int i=0; i<n; i++){
            prefix = (prefix + nums[i])%p;
            int need = (prefix-rem+p)%p;
            if(um.count(need)){
                min_len = min(min_len, i-um[need]);
            }
            um[prefix] =i;
        }
        return (min_len==INT_MAX || min_len ==n)? -1: min_len;
    }
};