class Solution {
public:
    bool checkMatch(char top, char curr){
        if((top=='(' && curr==')') || (top=='{' && curr=='}') || (top=='[' && curr==']')){
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;

        for(int i=0; i<n; i++){
            char curr = s[i];
            if(curr=='(' || curr== '{' || curr=='['){
                st.push(curr);
            }else{
                if(!st.empty()){
                    char top = st.top();
                    st.pop();
                    if(!checkMatch(top, curr)){
                        return false;
                    }
                }else{
                    return false;
                }
            }
        }

        if(st.empty()){
            return true;
        }
        return false;
    }
};