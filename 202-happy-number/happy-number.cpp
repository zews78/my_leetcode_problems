class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while(n!=1){
            if(s.count(n)){
                return false;
            }
            int num = n;
            int val =0;
            while(num){
                int digit = num%10;
                val += digit*digit;
                num = num/10;
            }
            s.insert(n);
            n = val;
        }
        return true;
    }
};