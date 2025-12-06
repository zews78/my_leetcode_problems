class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> um;

        stack<int> st;
        st.push(-1);

        for(int i=nums2.size()-1; i>=0; i--){
            int curr = nums2[i];
            while(st.top()!=-1 && st.top()<=curr){
                st.pop();
            }

            um[curr] = st.top();
            st.push(curr);
        }

        vector<int> ans;
        for(auto x: nums1){
            ans.push_back(um[x]);
        }

        return ans;
    }
};