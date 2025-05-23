class Solution {
public:
    int getSum(int a, int b) {
        while(b){
            int carry = a&b;
            a = a^b;
            b = carry <<1;
        }
        return a;
    }
};