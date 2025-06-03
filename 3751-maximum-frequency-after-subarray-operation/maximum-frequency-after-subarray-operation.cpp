class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int freq_k =0;
        for(auto x: nums){
            if(x==k) freq_k++;
        }
        // cout<<freq_k<<endl;

        int final_max_ans = INT_MIN;
        for(int m=1; m<=50; m++){
            if(m==k) continue;
            int max_ans = INT_MIN;
            int ans =0;
            for(auto x: nums){
                if(x==m) ans++;
                if(x==k) ans--;
                ans = max(ans, 0);
                max_ans = max(max_ans, ans);
            }
            final_max_ans = max(final_max_ans, max_ans);
        }
        // cout<<final_max_ans;
        return freq_k + final_max_ans;
    }
};