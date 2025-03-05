class Solution {
public:
    long long coloredCells(int n) {
        long long out = n;
        return 2*out*out -2*out +1;
        // return result;
    }
};