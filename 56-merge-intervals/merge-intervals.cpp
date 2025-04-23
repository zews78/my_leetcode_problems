class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> output;
        sort(intervals.begin(), intervals.end());

        int left = intervals[0][0];
        int right = intervals[0][1];

        for(int i=1; i<n; i++){
            int curr_left= intervals[i][0];
            int curr_right= intervals[i][1];
            if(curr_left<=right){
                right = max(curr_right, right);
            }else{
                output.push_back({left, right});
                left = curr_left;
                right = curr_right;
            }
        }
        output.push_back({left, right});

        return output;
    }
};