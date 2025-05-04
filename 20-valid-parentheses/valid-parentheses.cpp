#include <string>
class Solution {
public:
    bool checkMatching(char top, char x){
        if((x=='(' && top==')') || (x=='{' && top=='}') || (x=='[' && top==']')){
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        stack<char> st;
        for(auto x: s){
            if(x == '(' || x=='[' || x=='{'){
                st.push(x);
            }else{
                if(!st.empty()){
                    char top = st.top();
                    st.pop();
                    // cout<<x<<" "<<top<<endl;
                    if(!checkMatching(x, top)){
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