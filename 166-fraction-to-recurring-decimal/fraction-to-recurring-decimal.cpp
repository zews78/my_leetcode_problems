class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // return "";
        long long n = numerator;
        long long d = denominator;
        if(n ==0 ) return "0";

        string res = "";
        if(n<0 ^ d<0) res+="-";

        n = abs(n);
        d = abs(d);

        res += to_string(n/d);
        long long r = (n%d);
        if(r == 0) return res;

        res+= ".";

        unordered_map<int, int> um;

        while(r != 0){
            if(um.count(r)){
                res.insert(um[r], "(");
                res+=")";
                break;
            }

            um[r] = res.size();
            r = r*10;
            res+= to_string(r/d);
            r = r%d;
        }

        return res;

    }
};