class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> um;
        for(auto x: nums){
            um[x]++;
        }
        // if(um.size()==nums.size()/2){
        //     return true;
        // }
        int ans =0;
        for(auto x: um){
            if(x.second %2 !=0){
                return false;
            }
        }
        return true;
    }
};