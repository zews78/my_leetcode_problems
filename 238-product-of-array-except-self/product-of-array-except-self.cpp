class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1);
        vector<int> postfix(n, 1);
        vector<int> output;
        int prod_left= 1;
        int prod_right =1;
        // prefix.push_back(prod_left);
        for(int i=0; i<n; i++){
            prod_left *= nums[i];
            prefix[i]= (prod_left);
            prod_right *= nums[n-i-1];
            postfix[n-i-1] = prod_right;
        }

        for(int i=0; i<n; i++){
            int pre = (i==0)?1: prefix[i-1];
            int post = (i==n-1)?1:postfix[i+1];
            output.push_back(pre*post);
        }
        return output;
    }
};