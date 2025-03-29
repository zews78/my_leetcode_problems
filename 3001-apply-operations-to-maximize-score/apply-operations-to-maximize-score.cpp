class Solution {
public:
    static const int MOD = 1e9 + 7;

    // Function to count the number of distinct prime factors
    int getPrimeScore(int val) {
        int count = 0;
        for (int i = 2; i * i <= val; i++) {
            if (val % i == 0) {
                count++;
                while (val % i == 0) {
                    val /= i;
                }
            }
        }
        if (val > 1) count++;  // If remaining number is prime
        return count;
    }

    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> s(n, 0);

        // Compute prime scores for each element
        for (int i = 0; i < n; i++) {
            s[i] = getPrimeScore(nums[i]);
        }

        // Arrays to store previous and next dominant elements
        vector<int> nextDomEle(n, n), prevDomEle(n, -1);
        stack<int> st;

        // Compute previous dominant element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && s[st.top()] < s[i]) {
                st.pop();
            }
            if (!st.empty()) {
                prevDomEle[i] = st.top();
            }
            st.push(i);
        }

        // Clear the stack for the next loop
        while (!st.empty()) st.pop();

        // Compute next dominant element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && s[st.top()] <= s[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nextDomEle[i] = st.top();
            }
            st.push(i);
        }

        // Compute the number of operations each element contributes
        vector<long long> operations(n);
        for (int i = 0; i < n; i++) {
            operations[i] = (long long)(i - prevDomEle[i]) * (nextDomEle[i] - i);
        }

        // Max-heap to process elements in descending order
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        long long ans = 1;

        // Process elements until k becomes zero
        while (k > 0) {
            auto [val, index] = pq.top();
            pq.pop();
            long long operation = min(operations[index], (long long)k);
            ans = (ans * power(val, operation)) % MOD;
            k -= operation;
        }

        return ans;
    }

private:
    // Fast modular exponentiation
    long long power(long long base, long long exponent) {
        long long res = 1;
        while (exponent > 0) {
            if (exponent % 2 == 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exponent /= 2;
        }
        return res;
    }
};
