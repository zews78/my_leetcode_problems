class Solution {
public:
vector<string> splitBySpace(const string &s) {
    vector<string> result;
    string temp;

    for (char c : s) {
        if (c == ' ') {
            if (!temp.empty())
                result.push_back(temp);
            temp.clear();
        } else {
            temp += c;
        }
    }

    if (!temp.empty())
        result.push_back(temp);

    return result;
}
    string reverseWords(string s) {
        int n= s.size();
        vector<string> words = splitBySpace(s);
        
        string res = "";
        for(int i=words.size()-1; i>=0; i--){
            res+=words[i];
            if(i!=0){
                res+=" ";
            }
        }

        return res;
        
    }
};