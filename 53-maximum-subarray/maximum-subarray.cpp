class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_ans = INT_MIN;
        int ans =0;
        //if all val -ve
        // bool allNeg =true;
        // int max_neg = INT_MIN;
        // for(auto x: nums){
        //     if(x>=0){
        //         allNeg= false;
        //     }else{
        //         max_neg = max(max_neg, x);
        //     }
        // }
        // if(allNeg) return max_neg;

        for(auto x: nums){
            ans+=x;
            max_ans = max(ans, max_ans);

            if(ans<0){
                ans =0;
            }
        }
        return max_ans;
    }
};