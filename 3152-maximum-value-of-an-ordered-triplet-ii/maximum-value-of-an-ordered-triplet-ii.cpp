class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n= nums.size();
        vector<int> lmax(n, 0), rmax(n, 0);
        for(int i=1; i<n; i++){
            lmax[i] = max(lmax[i-1], nums[i-1]);
            rmax[n-i-1] = max(rmax[n-i], nums[n-i]);
        }
        // for(int i=0; i<n; i++){
        //     cout<<lmax[i]<<" ";
        // }cout<<endl;

        // for(int i=0; i<n; i++){
        //     cout<<rmax[i]<<" ";
        // }cout<<endl;

        long long res = LLONG_MIN;
        for(int i=1; i<n; i++){
            res = max(res, ((lmax[i]-nums[i])*(long long)rmax[i]));
        }

        return (res<0)?-1: res;
        // return 0;
    }
};