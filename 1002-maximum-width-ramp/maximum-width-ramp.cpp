class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int,int>> store;
        int n=nums.size();

        for(int i=0; i<n; i++){
            store.push_back({nums[i], i});
        }

        sort(store.begin(), store.end());


        int i=0, j=0;
        int res=0;
        while(j<n){
            if(store[i].second <= store[j].second){
                res = max(res,store[j].second-store[i].second);
                j++;
            }else{
                i++;
            }
        }

        return res;
    }
};