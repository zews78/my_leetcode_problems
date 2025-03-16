class Solution {
public:
    bool checkTimeFeasiblity(vector<int>& ranks, int cars, long long mid){
        long long count_max_cars=0;
        for(auto x: ranks){
            count_max_cars += static_cast<int>(sqrt(mid/x));
            // cout<<count_max_cars<<" ";
        }
        if(count_max_cars<cars) return false;
        return true;
    }
    
    long long repairCars(vector<int>& ranks, int cars) {
        long long i=0;
        long long j=ranks[0];
        for(int k=0; k<ranks.size(); k++){
            if(j>ranks[k]){
                j= ranks[k];
            }
        }
        j= j*cars*cars;
        long long ans;
        // cout<<checkTimeFeasiblity(ranks, cars, 15);
        while(i<=j){
            long long mid = i +(j-i)/2;
            if(checkTimeFeasiblity(ranks, cars, mid)){
                ans = mid;
                j= mid-1;
            }else{
                i =mid+1;
            }
        }
        return ans;
    }
};