class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        for(int i=n-1; i>=0; i--){
            if(s[i]=='1'){
                swap(s[i], s[n-1]);
                break;
            }
        }
        int i=0, j=0;
        while(j<n-1){
            if(s[j]=='1'){
                swap(s[i++], s[j++]);
            }
            else{
                j++;
            }
        }
        return s;
    }
};