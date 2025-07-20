class Solution {
public:
    const int MOD = 1e9 + 7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> um;
        for(int i=0; i<points.size(); i++){
            int u = points[i][0];
            int v = points[i][1];
            um[v]++;
        }

        int output = 1;
        vector<int> lines;

        for(auto x: um){
            // for(auto um)
            int _size = x.second;
            if(_size>=2){
                int ncr= nc2(_size);
                lines.push_back(ncr);
            }
        }

        long long total = 0;
        long long sub = 0;
        for(auto x: lines){
            total+=x;
            if(x>=2){
                sub+= nc2(x);
            }
        }
        long long comb_total = nc2(total);
        

        

        if(lines.size()<2) return 0;
        long long result = (comb_total - sub + MOD)%MOD;
        return result;
    }
    int nc2(int n){
        return ((1LL*n*(n -1))/2)%MOD;
    }
    // int C(int n, int r) {
    //     if (n < r) return 0;
    //     if (n - r < r) return C(n, n - r);
    
    //     int res = 1;
    //     for (int i = 0; i < r; i++) {
    //         res = (1LL * res * (n - i)) % MOD;
    //         res = (1LL * res * modinv(i + 1)) % MOD;
    //     }
    //     return res;
    // }
    // int modinv(int a) {
    //     return power(a, MOD - 2);
    // }

};