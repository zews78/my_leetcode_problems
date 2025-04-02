class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n= nums.size();
        long long max_val = LLONG_MIN;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    max_val = max(max_val, (long long)((nums[i]-nums[j])*(long long)nums[k]));
                }
            }
        }
        return (max_val<0)? 0: max_val;
    }
};