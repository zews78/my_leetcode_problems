class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int st=0;
        int end=0;
        unordered_map<char, int> um;
        int n = s.size();

        int l_subs = 0;

        while(end<n){
            um[s[end]]++;

            if(um.size()<end-st+1){
                um[s[st]]--;
                if(um[s[st]]==0){
                    um.erase(s[st]);
                }
                st++;
            }

            l_subs = max(l_subs, end-st+1);
            end++;
            
        }

        return l_subs;
    }
};