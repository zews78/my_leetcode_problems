class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int st=0;
        int end =0;
        int n= s.size();
        int max_len =0;

        unordered_map<int, int> um; //should be <char,int> however <int,int> will also work due to implicit conversion.
        while(end<n){
            um[s[end]]++;

            while(um.size()<(end-st+1)){
                um[s[st]]--;
                if(um[s[st]]==0){
                    um.erase(s[st]);
                }
                st++;
            }
            max_len = max(max_len, (end-st+1));
            end++;
        }
        return max_len;
    }
};