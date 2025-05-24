class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        //check if already a zero arr
        bool IsZeroArr=true;
        for(auto x: nums){
            if(x>0){
                IsZeroArr = false;
                break;
            }
        }
        if(IsZeroArr) return 0;
        
        int k = -1;
        int i=0, j=queries.size()-1;
        while(i<=j){
            int mid = i+(j-i)/2;
            if(checkZeroArr(nums, queries, mid)){
                k = mid;
                j = mid-1;
            }else{
                i = mid+1;
            }
        }
        return (k>=0)? k+1: k;
    }
    bool checkZeroArr(vector<int> nums, vector<vector<int>>& queries, int k){
        vector<int> diff(nums.size()+1, 0);
        for(int i=0; i<=k; i++){
            int st= queries[i][0];
            int end = queries[i][1];
            int val = queries[i][2];
            diff[st]+= val;
            diff[end+1]-=val;
        }

        int values=0;
        for(int i=0; i<nums.size(); i++){
            values+=diff[i];
            if(nums[i]>values){
                return false;
            }
        }
        return true;
    }

};