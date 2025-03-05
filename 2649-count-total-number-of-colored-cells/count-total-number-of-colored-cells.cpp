class Solution {
public:
    long long coloredCells(int n) {
        // long long result= 1;
        // while(n){
        //     n--;
        //     result= result + 4*n;
        // }
        // return result;

        // long long out = n;
        return (long long)2*n*n -2*n +1;
        // return result;
    }
};