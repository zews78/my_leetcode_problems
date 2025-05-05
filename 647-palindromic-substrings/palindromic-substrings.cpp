class Solution {
public:
    int countSubstrings(string s) {
        int n= s.size();
        int count =0;
        for(int k=0; k<n; k++){
            int i=k, j=k;
            while(i>=0 && j<n && s[i]==s[j]){
                count++;
                i--; j++;
            }

            i=k, j=k+1;
            while(i>=0 && j<n && s[i]==s[j]){
                count++;
                i--; j++;
            }
        }

        return count;
    }
};