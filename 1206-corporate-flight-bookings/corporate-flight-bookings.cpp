class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n, 0);
        for(int i=0; i<bookings.size(); i++){
            int st = bookings[i][0];
            int end = bookings[i][1];
            int val = bookings[i][2];
            for(int j=st; j<=end; j++){
                ans[j-1]+=val;
            }
        }
        return ans;
    }
};