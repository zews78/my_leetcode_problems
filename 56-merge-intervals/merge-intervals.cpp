class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int st_ele = intervals[0][0];
        int end_ele = intervals[0][1];
        int n = intervals.size();
    
        vector<vector<int>> output;

        for(int i=1; i<n; i++){
            int curr_x = intervals[i][0];
            int curr_y = intervals[i][1];

            if(curr_x<= end_ele){
                end_ele = max(curr_y, end_ele);
            }else{
                output.push_back({st_ele, end_ele});
                st_ele = curr_x;
                end_ele = curr_y;
            }
        }
        output.push_back({st_ele, end_ele});
        return output;
    }
};