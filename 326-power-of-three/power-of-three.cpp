class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n>0 && 1162261467%n==0){
            return true;
        }
        return false;
        // if(n==1) return true;
        // if(n<=0) return false;

        // return (n%3==0) && isPowerOfThree(n/3);
    }
};