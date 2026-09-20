class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        int roll_len =2*n;
        stack<int> st;
        st.push(INT_MIN);
        vector<int> res(n);

        for(int i=roll_len; i>=0; i--){
            int val=nums[i%n];
            while(st.top()!=INT_MIN && st.top()<=val){
                st.pop();
            }
            res[i%n]=(st.top()!=INT_MIN)?st.top():-1;
            st.push(val);
        }

        return res;
    }
};