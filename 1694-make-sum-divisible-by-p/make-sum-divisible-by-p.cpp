class Solution {
public:
int minSubarray(vector<int>& nums, int p) {
    long long totalSum = 0;
    for(int x : nums) totalSum += x;
    
    int rem = totalSum % p;
    if(rem == 0) return 0; // already divisible
    
    unordered_map<int,int> mp;
    mp[0] = -1; // prefix before array starts
    
    long long prefix = 0;
    int ans = nums.size();
    
    for(int i = 0; i < nums.size(); i++){
        prefix = (prefix + nums[i]) % p;
        int needed = (prefix - rem + p) % p;
        
        if(mp.count(needed)){
            ans = min(ans, i - mp[needed]);
        }
        
        mp[prefix] = i; // store/update latest prefix index
    }
    
    return (ans == nums.size() ? -1 : ans);
}
};