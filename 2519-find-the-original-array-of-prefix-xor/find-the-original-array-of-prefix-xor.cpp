class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> output;
        int n=pref.size();

        int final_out_xorr =0;

        for(int i=0; i<n; i++){
            int out_pref_xorr=0;
            out_pref_xorr^= final_out_xorr;
            out_pref_xorr ^= pref[i];
            final_out_xorr ^= out_pref_xorr;
            output.push_back(out_pref_xorr);
        }

        return output;
    }
};