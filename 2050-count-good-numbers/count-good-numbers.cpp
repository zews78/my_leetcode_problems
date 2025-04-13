class Solution {
public:
    int MOD = 1e9 +7;
    long long power(long long x, long long y){
        long long power = 1;
        while(y){
            if(y&1){
                power= power * x%MOD;
            }
            x = (long long)x * x % MOD;
            y = y>>1;
            // cout<<1<<" ";
        }
        return power;
    }
    int countGoodNumbers(long long n) {
        return power(5, (n+1)/2) * power(4, n/2)%MOD;
        // return (long long)power(5, n/2)%MOD;
    }
};