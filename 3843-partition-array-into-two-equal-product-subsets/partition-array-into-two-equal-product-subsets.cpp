class Solution {
public:
    void solve(int n, vector<int>& nums, long long target, unordered_set<int>& set, bool& target_found){
        if(n==0){
            if(target==1){
                target_found = true;
            }
            return;
        }
        if(nums[n-1]<=target && target%nums[n-1]==0){
            set.insert(nums[n-1]);
            solve(n-1, nums, target/nums[n-1], set, target_found);
            if(target_found) return;
            set.erase(nums[n-1]);
        }
        solve(n-1, nums, target, set, target_found);
    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        unordered_set<int> set;
        bool target_found = false;
        solve(nums.size(), nums, target, set, target_found);
        if(set.size()==nums.size() || set.size()==0){
            return false;
        }
        // for(auto x: set){
        //     cout<<x<<" ";
        // }
        long long product2=1;
        for(auto x: nums){
            if(!set.count(x)){
                product2*= x;
            }
        }
        if(product2 == target){
            return true;
        }
        return false;
    }
};