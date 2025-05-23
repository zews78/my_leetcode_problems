class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n, 0);
        vector<int> diff(n+1, 0);
        for(int i=0; i<bookings.size(); i++){
            int st = bookings[i][0];
            int end = bookings[i][1];
            int val = bookings[i][2];
            diff[st-1]+=val;
            diff[end]-=val;
        }

        int seats =0;
        for(int i=0; i<n; i++){
            seats += diff[i];
            ans[i] = seats;
        }
        return ans;
    }
};