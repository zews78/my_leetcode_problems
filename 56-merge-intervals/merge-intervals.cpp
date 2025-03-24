class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> output;
        sort(intervals.begin(), intervals.end());

        int left = intervals[0][0];
        int right =intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            int current_left = intervals[i][0];
            int current_right = intervals[i][1];
            
            if(current_left<= right){
                right = max(right, current_right);
            }else{
                output.push_back({left, right});
                left = current_left;
                right = current_right;
            }


        }
        output.push_back({left, right});
        return output;
    }
};