class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int> res(queries.size());
        vector<int> xorr_pref(n+1);

        xorr_pref[0]=0;
        for(int i=0; i<n; i++){
            xorr_pref[i+1] = arr[i]^xorr_pref[i];
        }

        for(int i=0; i<queries.size(); i++){
            int R=queries[i][1];
            int L=queries[i][0];

            res[i] = xorr_pref[R+1]^xorr_pref[L];
        }

        return res;
    }
};