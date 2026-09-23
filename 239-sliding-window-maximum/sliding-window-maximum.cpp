class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> dq;
        vector<int> res;
        int j=0;
        while(j<k){
            while(!dq.empty() && nums[dq.front()]<=nums[j]){
                dq.pop_front();
            }
            dq.push_front(j);
            j++;
        }
        res.push_back(nums[dq.back()]);


        int i=0;
        while(j<n){
            if(!dq.empty() && dq.back()<=i){
                dq.pop_back();
            }

            while(!dq.empty() && nums[dq.front()]<=nums[j]){
                dq.pop_front();
            }
            dq.push_front(j);
            res.push_back(nums[dq.back()]);
            j++;
            i++;
        }

        return res;
    }
};