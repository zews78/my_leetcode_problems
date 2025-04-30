class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0;
        int j=0;
        unordered_map<char, int> um;
        int max_output = 0;

        while(j<n){
            um[s[j]]++;
            
            while(um.size()<(j-i+1)){
                um[s[i]]--;
                if(um[s[i]]==0){
                    um.erase(s[i]);
                }
                i++;
            }
            max_output = max(max_output, j-i+1);
            j++;
        }
        return max_output;
    }
};