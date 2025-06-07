class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        for(auto x: wordDict){
            set.insert(x);
        }
        vector<string> temp;
        vector<string> output;
        solve(0, s, set, temp, output);
        return output;
    }

    void solve(int i, string s, unordered_set<string>& set, vector<string> temp, vector<string>& output){
        if(i==s.size()){
            string construct = "";
            for(int i=0; i<temp.size(); i++){
                construct+= temp[i];
                if(i!=temp.size()-1){
                    construct+=" ";
                }
            }
            output.push_back(construct);
            return;
        }

        for(int ind=i; ind<s.size(); ind++){
            if(set.count(s.substr(i, ind-i+1))){
                temp.push_back(s.substr(i, ind-i+1));
                solve(ind+1, s, set, temp, output);
                temp.pop_back();
            }
        }
    }
};