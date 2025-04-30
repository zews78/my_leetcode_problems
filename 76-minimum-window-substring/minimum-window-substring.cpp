class Solution {
public:
    bool checkMatch(unordered_map<char, int>& umt, unordered_map<char, int>& ums){
        for(auto c: umt){
            if(ums.count(c.first)){
                if(ums[c.first]<c.second){
                    return false;
                }
            }else{
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n = s.size();
        if(t.size()>n){
            return "";
        }

        unordered_map<char, int> umt;
        unordered_map<char, int> ums;

        for(auto x: t){
            umt[x]++;
        }
        int min_output=INT_MAX;
        string output_string="";
        pair<int, int> output_ind;

        int i=0;
        int j=0;
        while(j<n){
            ums[s[j]]++;

            while(checkMatch(umt, ums)){
                // cout << "{" << i << ", " << j << "} ";
                if((j-i+1)<min_output){
                    output_ind = {i, j};
                    min_output = (j-i+1);
                }
                ums[s[i]]--;
                if(ums[s[i]]==0){
                    ums.erase(s[i]);
                }
                i++;
            }
            j++;
        }

        int st = output_ind.first;
        int end = output_ind.second;
        while(st<=end){
            output_string+=s[st];
            st++;
        }
        return (min_output!=INT_MAX)? output_string: "";
    }
};