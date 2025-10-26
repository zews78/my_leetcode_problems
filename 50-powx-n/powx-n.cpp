class Solution {
public:
    double myPow(double x, int n) {
        // 1 0 1 1 = 11
        // 2^3  2^2  2^1 2^0 
        // 8 4 2 1
        // 2^8 2^4 2^2  2^1
        long long N = n;
        if(N<0){
            x = 1/x;
            N = -N;
        }

        double res =1;
        while(N){
            if(N&1){
                res *= x;
            }
            x = x*x;
            N = N>>1;
        }
        return res;


    }
};