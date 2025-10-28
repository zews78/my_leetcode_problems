class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1;
        int cnt1=0;
        int ele2;
        int cnt2=0;

        int n= nums.size();

        for(int i=0; i<nums.size(); i++){
            if(ele1==nums[i]){
                cnt1++;
            }else if(ele2==nums[i]){
                cnt2++;
            }else if(cnt1==0){
                ele1 = nums[i];
                cnt1=1;
            }else if(cnt2==0){
                ele2 = nums[i];
                cnt2 =1;
            }else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1=0;
        cnt2=0;
        for(auto x: nums){
            if(x==ele1){
                cnt1++;
            }
            else if(x==ele2){
                cnt2++;
            }
        }

        vector<int> res;
        if(cnt1>n/3) res.push_back(ele1);
        if(cnt2>n/3) res.push_back(ele2);

        return res;
    }
};