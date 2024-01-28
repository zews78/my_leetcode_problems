class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start= 0;
        int end=0;
        int n =s.size();
        int max_len=0;
        unordered_map<char,int> um;
        while(end<n){
            um[s[end]]++;
            while(um.size()<end-start+1){
                um[s[start]]--;
                if(um[s[start]]==0){
                    um.erase(s[start]);
                }
                start++;
            }
            
            max_len= max(max_len, end-start+1);
            end++;
        }
        return max_len;
    }
};