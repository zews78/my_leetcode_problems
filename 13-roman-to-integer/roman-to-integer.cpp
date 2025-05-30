class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> um;
        um['I'] = 1;
        um['V'] = 5;
        um['X'] = 10;
        um['L'] = 50;
        um['C'] = 100;
        um['D'] = 500;
        um['M'] = 1000;

        int output = 0;
        int i;
        for(i=0; i<s.size()-1; i++){
            if(um[s[i]] < um[s[i+1]]){
                output-= um[s[i]];
            }else{
                output+=um[s[i]];
            }
        }
        output+=um[s[i]];
        return output;

    }
};