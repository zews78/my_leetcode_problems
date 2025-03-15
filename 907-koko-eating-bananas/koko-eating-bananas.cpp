class Solution {
public:
    bool checkAllEatable(vector<int>& piles, int h, int mid){
        if(mid==0) return false;
        long long count_hours=0;
        for(int i=0; i<piles.size(); i++){
            count_hours += ceil(piles[i]/(double)mid);
            // cout<<count_hours<<" ";
        }
        if(count_hours<=h) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int i=1;
        int j=piles[0];
        for(auto x: piles){
            j = max(j, x);
        }
        // cout<<j<<endl;
        int ans;
        // cout<<checkAllEatable(piles, h, 21)<<endl;
        while(i<=j){
            int mid = i+(j-i)/2;
            // cout<<mid<<"-"<<checkAllEatable(piles, h, mid)<<" ";
            if(checkAllEatable(piles, h, mid)){
                ans = mid;
                j = mid-1;
            }else{
                i = mid+1;
            }
        }
        return ans;

    }
};