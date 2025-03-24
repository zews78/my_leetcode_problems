class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int freeCount =0;
        int latestEnd =0;
        sort(meetings.begin(), meetings.end());
        for(auto x: meetings){
            int start = x[0];
            int end = x[1];
            if(start>latestEnd){
                freeCount += start- latestEnd -1;
            }
            latestEnd = max(latestEnd, end);
        }
        freeCount += days-latestEnd;

        return freeCount;
    }
};