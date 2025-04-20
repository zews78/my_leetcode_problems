class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;

        for(auto x: nums){
            int k = x;
            while(!st.empty() && st.top()>k){
                k = max(k, st.top());
                st.pop();
            }
            st.push(k);
        }
        return st.size();
    }
};