class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i=1;
        int n= nums.size();
        while(i<n){
            int curr = nums[i]-1;
            if(nums[i]!=nums[curr] && curr!=i){
                swap(nums[i], nums[curr]);
            }else{
                i++;
            }
        }

        vector<int> ans;
        for(auto x: nums){
            cout<<x<<" ";
        }
        for(int i=0; i<n; i++){
            if(nums[i]-1!=i){
                ans.push_back(i+1);
            }
        }

        return ans;
    }
};