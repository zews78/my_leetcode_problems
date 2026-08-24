class Solution {
public:
    bool checkFeasible(vector<int>& weights, int days, int ship_wt){
        int cal_days=1;
        int n=weights.size();
        
        int temp_wt=0;
        for(auto wt: weights){
            if(wt>ship_wt) return false;

            if(temp_wt+wt > ship_wt){
                cal_days++;
                temp_wt=0;
            }
            temp_wt+=wt;
        }

        return cal_days<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int total_wt=0;
        for(int i=0; i<n; i++){
            total_wt+=weights[i];
        }

        int st=1;
        int end =total_wt;

        while(st<end){
            int mid=st+(end-st)/2;

            if(checkFeasible(weights, days, mid)){
                end=mid;
            }else{
                st=mid+1;
            }
        }
        
        return end;
    }
};