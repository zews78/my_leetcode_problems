class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> om;
        for(auto x: nums){
            om[x]++;
        }
        int summ =0;
        int max_freq = om.begin()->second;
        for(auto x: om){
            if(x.second >max_freq){
                // summ= x.second;
                max_freq = x.second;
            }
        }
        for(auto i=om.begin(); i!=om.end(); i++){
            // cout<<i->second<<" ";
            if(i->second==max_freq){
                summ += i->second;
            }
        }
        return summ;
        
    }
};