class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        unordered_map<char, int> um;

        int result =0;
        int i=0;
        int j=0;
        while(j<n){
            um[s[j]]++;

            while(um.size()==3){
                // result+=1;
                result+=(n-j);
                um[s[i]]--;
                if(um[s[i]]==0){
                    um.erase(s[i]);
                }
                i++;
            }
            j++;
        }
        return result;
    }
};