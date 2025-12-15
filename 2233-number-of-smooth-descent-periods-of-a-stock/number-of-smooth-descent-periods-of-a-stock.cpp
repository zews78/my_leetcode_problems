class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long res =0;
        int n = prices.size();
        int prev = prices[0];
        int cont_cnt =1;
        for(int i=1; i<n; i++){
            int curr = prices[i];
            if(curr==prev-1){
                cont_cnt++;
            }else{
                res += (long long)cont_cnt*(cont_cnt+1)/2;
                cont_cnt =1;
            }
            prev = curr;
        }
        res+= (long long)cont_cnt*(cont_cnt+1)/2;
        return res;
    }
};