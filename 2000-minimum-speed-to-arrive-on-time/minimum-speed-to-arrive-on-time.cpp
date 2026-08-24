class Solution {
public:
    bool checkFeasible(vector<int>& dist, int speed, double hour){
        double cal_hour=0.00;
        int n=dist.size();
        for(int i=0; i<n-1; i++){
            cal_hour+=(dist[i]+speed-1)/speed;
            if (cal_hour > hour) return false;
        }
        cal_hour+=(double)dist[n-1]/speed;

        if(cal_hour<=hour){
            return true;
        }
        return false;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        int s=1;
        int e=10000000;
        if(hour<=n-1) return -1;

        while(s<e){
            int mid=s+(e-s)/2;

            if(checkFeasible(dist, mid, hour)){
                e=mid;
            }else{
                s=mid+1;
            }
        }
        return e;
    }
};