
class Solution {
public:
    static const int MOD = 1e9 +7;
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
        for(int i=0; i<n; i++){
            s[i] = getPrimeScore(nums[i]);
        }
        vector<int> nextDomEle(n, n);
        vector<int> prevDomEle(n, -1);

        stack<int> st_prev;
        stack<int> st_next;
        for(int i=0; i<n; i++){
            while(!st_prev.empty() && s[st_prev.top()] < s[i]){
                st_prev.pop();
            }
            if(!st_prev.empty()){
                prevDomEle[i]= st_prev.top();
            }

            st_prev.push(i);

            // ---------------------

            while(!st_next.empty() && s[st_next.top()] <= s[n-i-1]){
                st_next.pop();
            }
            if(!st_next.empty()){
                nextDomEle[n-i-1]= st_next.top();
            }

            st_next.push(n-i-1);

        }
        // for(auto x: s){
        //     cout<<x<<" ";
        // }cout<<endl;
        // for(int i=0; i<n; i++){
        //     cout<<prevDomEle[i]<<" ";
        // }cout<<endl;
        // for(int i=0; i<n; i++){
        //     cout<<nextDomEle[i]<<" ";
        // }
        vector<long long> operations(n);
        for(int i=0; i<n; i++){
            operations[i] = (long long)(i-prevDomEle[i])*(nextDomEle[i]-i);
        }

        priority_queue<pair<int, int>> pq;

        for(int i=0; i<n; i++){
            pq.push({nums[i], i});
        }

        long long ans =1;

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
    // Helper function to compute the power of a number modulo MOD
    long long power(long long base, long long exponent) {
        long long res = 1;

        // Calculate the exponentiation using binary exponentiation
        while (exponent > 0) {
            // If the exponent is odd, multiply the result by the base
            if (exponent % 2 == 1) {
                res = ((res * base) % MOD);
            }

            // Square the base and halve the exponent
            base = (base * base) % MOD;
            exponent /= 2;
        }

        return res;
    }
};