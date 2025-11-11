class Solution {
public:
    bool isPallindrome(string s){
        int i=0;
        int e=s.size()-1;
        bool isPall = true;
        while(i<e){
            if(s[i]!=s[e]){
                return false;
            }
            i++;e--;
        }
        return isPall;
    }
    vector<vector<string>> partition(string s) {
        int curr= 0;
        int prev = -1;
        int n= s.size();

        vector<string> pallindrome_set;
        vector<vector<string>> all_pallindromes;
        solve(curr, prev, n, s, pallindrome_set, all_pallindromes);
        return all_pallindromes;
    }

    void solve(int curr, int prev, int n, string s, vector<string> pallindrome_set, vector<vector<string>> &all_pallindromes){
        if(curr==n){
            all_pallindromes.push_back(pallindrome_set);
            return;
        }

        for(int i=curr; i<n; i++){
            int st = curr;
            int end = i;
            string temp_set = s.substr(st, end-st+1);
            if(isPallindrome(temp_set)){
                pallindrome_set.push_back(temp_set);
                solve(i+1, prev, n, s, pallindrome_set, all_pallindromes);
                pallindrome_set.pop_back();
            }
        }
    }
};