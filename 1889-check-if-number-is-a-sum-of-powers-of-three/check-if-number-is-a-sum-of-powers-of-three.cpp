class Solution {
public:
long long int cubeRoot(long long int n) {
    long long int low = 0, high = n, mid;
    
    while (low <= high) {
        mid = low + (high - low) / 2;  // Avoids potential overflow in `(low + high) / 2`

        // Check if mid^3 > n without overflow
        if (mid > 0 && mid > n / (mid * mid)) {  
            high = mid - 1;
        } else {
            if (mid * mid * mid == n) return mid;  // Perfect cube case
            low = mid + 1;
        }
    }

    return high;  // The integer cube root (floor value)
}

const long long MOD = 1e9 + 7; // Use a large prime number

long long power(long long x, long long n) {
    long long output = 1;
    x %= MOD;  // Reduce x initially to prevent unnecessary overflow

    while (n > 0) {
        if (n % 2 == 1)  // If n is odd, multiply x with output
            output = (output * x) % MOD;
        x = (x * x) % MOD;  // Square x under modulo
        n /= 2;  // Reduce exponent by half
    }

    return output;
}
    // bool max_sum_possible(int i, int n){
    //     // if(i<0 || n==0){
    //     //     return 0;
    //     // }
    //     // if(power(3,i)<=n){
    //     //     return max(power(3,i)+max_sum_possible(i-1, n-power(3,i)), max_sum_possible(i-1, n));
    //     // }else{
    //     //     return max_sum_possible(i-1, n);
    //     // }
    //     if(i<0){
    //         if(n==0){
    //             return true;
    //         }else{
    //             return false;
    //         }
    //     }

    //     if(pow(3,i)<=n){
    //         return max_sum_possible(i-1, n-pow(3,i)) || max_sum_possible(i-1, n);  
    //     }else{
    //         return max_sum_possible(i-1, n);
    //     }
    // }

    bool max_possible(int power, int n){
        if(n==0) return true;
        if(pow(3, power)> n) return false;

        return max_possible(power+1, n-pow(3, power)) || max_possible(power+1, n);
    }


    bool checkPowersOfThree(int n) {
        return max_possible(0, n);
    }
};