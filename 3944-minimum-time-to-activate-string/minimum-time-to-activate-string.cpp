class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
        int n = s.length();
        int low = 0, high = n - 1, ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            vector<bool> isStar(n);
            for (int i = 0; i <= mid; i++) {
                isStar[order[i]] = true;
            }

            long good = 0, count = 0;
            for (int i = 0; i < n; i++) {
                if (!isStar[i]) {
                    count++;
                } else {
                    good += (count * (count + 1)) / 2;
                    count = 0;
                }
            }
            if (count > 0) {
                good += (count * (count + 1)) / 2;
            }

            long total = (long) n * (n + 1) / 2;
            long valid = total - good;

            if (valid >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;

    }
};