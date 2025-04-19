class Solution {
public:
    int cal_nCr(int n, int r){
        long long result =1;
        for(int i=1; i<=r; i++){
            result *= (n-r+i);
            result/=i;
        }
        return result;
        
    }
    int uniquePaths(int m, int n) {
        return cal_nCr(m+n-2, n-1);
    }
};