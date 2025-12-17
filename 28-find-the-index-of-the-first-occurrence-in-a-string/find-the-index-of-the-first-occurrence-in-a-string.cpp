class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.size();
        int n = needle.size();
        for(int i=0; i<h; i++){
            int curr = i;
            int ndl_idx = 0;
            while(curr<h && ndl_idx<n && haystack[curr]==needle[ndl_idx]){
                curr++;
                ndl_idx++;
            }
            if(ndl_idx == n){
                return i;
            }
        }
        return -1;
    }
};