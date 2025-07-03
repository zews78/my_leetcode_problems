class Solution {
public:
    int myAtoi(string s) {
        int output=0;
        int n =s.size();
        int i=0;
        while(i<n && s[i]==' '){
            i++;
        }
        bool isNeg = false;
        if(i<n && (s[i]=='-' || s[i]=='+')){
            if(s[i]=='-'){
                isNeg = true;
            }
            i++;
        }

        while(i<s.size() && (s[i]-'0')>=0 && (s[i]-'0')<=9){
            cout<<output<<" ";
            int digit = s[i] - '0';
            if (output > (INT_MAX - digit) / 10) {
                return isNeg ? INT_MIN : INT_MAX;
            }
            output = 10*output + digit;
            i++;
        }

        return (isNeg)? -output: output;
    }
};