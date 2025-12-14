class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i=0;
        while(s[i]==' '){
            i++;
        }

        bool isNegative = false;
        if(i<n && (s[i]=='-' || s[i]=='+')){
            if(s[i]=='-'){
                isNegative = true;
            }
            i++;
        }

        int res =0;
        while(i<n && s[i]>='0' && s[i]<='9'){
            int digit = s[i]-'0';
            if((INT_MAX - digit)/10 <res){
                return (isNegative)? INT_MIN: INT_MAX;
            }
            res = res*10 + digit;
            i++;
        }

        return (isNegative)?-res: res;


    }
};