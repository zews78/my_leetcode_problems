class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if(n==0){
            return {newInterval};
        }
        vector<vector<int>> res;
        int i=0;
        bool postMerge= false;
        while(i<n){
            int new_st = newInterval[0];
            int curr_end = intervals[i][1];
            if(curr_end<new_st || postMerge){
                res.push_back(intervals[i]);
                i++;
            }else{
                int st = min(intervals[i][0], newInterval[0]);
                int end = newInterval[1];
                while(i<n && newInterval[1]>=intervals[i][0]){
                    end = max(end, intervals[i][1]);
                    i++;
                }
                res.push_back({st, end});
                postMerge =true;
            }
        }
        if(!postMerge){
            res.push_back(newInterval);
        }
        return res;
    }
};