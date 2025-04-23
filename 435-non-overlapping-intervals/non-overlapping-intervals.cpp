class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int min_count =0;
        sort(intervals.begin(), intervals.end());

        int left = intervals[0][0];
        int right = intervals[0][1];
        for(int i=1; i<n; i++){
            int curr_left = intervals[i][0];
            int curr_right = intervals[i][1];
            if(curr_left<right){
                min_count++;
                right = min(right, curr_right);
            }else{
                left = curr_left;
                right = curr_right;
            }
        }
        return min_count;

    }
};