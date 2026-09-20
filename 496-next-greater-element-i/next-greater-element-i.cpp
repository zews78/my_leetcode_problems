class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;

        unordered_map<int, int> um;
        stack<int> st;

        int n = nums2.size();

        for(int i=0; i<n; i++){
            int curr=nums2[i];
            while(!st.empty() && st.top()<curr){
                um[st.top()]=curr;
                st.pop();
            }

            st.push(curr);

        }

        

        for(int i=0; i<nums1.size(); i++){
            res.push_back((um.count(nums1[i]))?um[nums1[i]]:-1);
        }

        return res;

    }
};