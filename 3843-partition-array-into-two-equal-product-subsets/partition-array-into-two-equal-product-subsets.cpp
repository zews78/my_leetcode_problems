class Solution {
public:
    typedef __int128 ll;
    // void solve(int n, vector<int>& nums, long long target, unordered_set<int>& set, bool& target_found){
    //     if(n==0){
    //         if(target==1){
    //             target_found = true;
    //         }
    //         return;
    //     }
    //     if(nums[n-1]<=target && target%nums[n-1]==0){
    //         set.insert(nums[n-1]);
    //         solve(n-1, nums, target/nums[n-1], set, target_found);
            
    //         set.erase(nums[n-1]);
    //     }
    //     solve(n-1, nums, target, set, target_found);
    // }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n = nums.size();
        ll total = 1;
        for (int x : nums) {
            total *= x;
            if (total > (ll)target * target) return false;
        }

        if (total != (ll)target * target) return false;
        return true;
    }
};