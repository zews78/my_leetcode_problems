class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto x: asteroids){
            if(x>0){
                st.push(x);
            }else{
                while(!st.empty() && st.top()>0 && st.top()<abs(x)){
                    st.pop();
                }
                if(!st.empty() && st.top()>0 && st.top()==abs(x)){
                    st.pop();
                    continue;
                }
                if(!st.empty() && st.top()>0 && st.top()>abs(x)){
                    continue;
                }
                st.push(x);
            }

        }
        vector<int> output;
        while(!st.empty()){
            output.push_back(st.top());
            st.pop();
        }
        reverse(output.begin(), output.end());
        return output;
    }
};