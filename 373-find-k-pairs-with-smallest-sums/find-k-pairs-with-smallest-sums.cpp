class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;

        int n1=nums1.size();
        int n2=nums2.size();

        for(int i=0; i<min(k, n1); i++){
            long long sum= nums1[i]+nums2[0];
            pq.push({sum, i, 0});
        }

        vector<vector<int>> res;

        while(!pq.empty() && res.size()<k){
            auto [sum, i, j]= pq.top();
            pq.pop();
            res.push_back({nums1[i], nums2[j]});

            long long nextSum;
            if(j+1<n2){
                nextSum=nums1[i]+nums2[j+1];
                pq.push({nextSum, i, j+1});
            }
            
        }
        
        return res;
    }
};