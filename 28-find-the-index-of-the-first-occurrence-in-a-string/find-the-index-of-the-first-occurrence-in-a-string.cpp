class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        int h = haystack.size();
        if(n==0) return 0;
        if(n>h) return -1;

        //construct lps(longest prefix suffix) for needle
        // the significance of lps is it tracks the repeated chars!
        int prev=0;
        int i=1;
        vector<int> lps(n, 0);
        while(i<n){
            if(needle[i]==needle[prev]){
                lps[i] = prev+1;
                i++;
                prev++;
            }
            else if(prev==0){
                lps[i] =0;
                i++; //imp
            }else{
                prev = lps[prev-1];
            }
        }


        // iterate over haystack
        //track back on needle if needed

        i=0;
        int j=0;
        while(i<h){
            if(haystack[i]==needle[j]){
                i++; j++;
            }else{
                if(j>0){
                    j = lps[j-1];
                }else{
                    j=0;
                    i++;
                }
            }
            if(j==n){
                return (i-n);
            }
        }

        return -1;
    }
};