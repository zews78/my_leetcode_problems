class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<int, int>> dq;
        vector<int> ans;

        int j=0;
        while(j<k){
            while(!dq.empty() && dq.front().first < nums[j]){
                dq.pop_front();
            }
            dq.push_front({nums[j], j});
            j++;
        }
        ans.push_back(dq.back().first);
        int i=0;
        while(j<n){
            //pop start
            if(dq.back().second <= i){
                dq.pop_back();
            }

            //push in monotonic fashion
            while(!dq.empty() && dq.front().first < nums[j]){
                dq.pop_front();
            }
            dq.push_front({nums[j], j});
            ans.push_back(dq.back().first);
            i++; j++;
        }

        return ans;
    }
};