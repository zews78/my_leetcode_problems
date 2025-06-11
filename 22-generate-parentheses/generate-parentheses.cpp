class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> final;
        string temp;
        solve(n, n, temp, final);
        return final;
    }

    void solve(int open_br, int close_br, string temp, vector<string>& final){
        if(open_br==0 && close_br==0){
            final.push_back(temp);
            return;
        }

        if(open_br>0){
            temp.push_back('(');
            solve(open_br-1, close_br, temp, final);
            temp.pop_back();
        }

        if(close_br>0 && close_br-open_br>0){
            temp.push_back(')');
            solve(open_br, close_br-1, temp, final);
            temp.pop_back();
        }

    }
};