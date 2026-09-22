class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int max_area=0;
        stack<int> st;

        for(int i=0; i<n; i++){
            int curr=heights[i];
            while(!st.empty() && heights[st.top()]>=curr){
                int top = st.top(); st.pop();

                int nse = i;
                int pse = (st.empty())?-1:st.top();

                int curr_area = heights[top]*(nse-pse-1);
                max_area = max(max_area, curr_area);
            }
            st.push(i);
        }
        while(!st.empty()){
            int top = st.top(); st.pop();

            int nse = n;
            int pse = (st.empty())?-1:st.top();

            int curr_area = heights[top]*(nse-pse-1);
            max_area = max(max_area, curr_area);
        }
        return max_area;

    }
};