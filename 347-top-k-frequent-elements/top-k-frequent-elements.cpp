class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        for(auto x: nums){
            um[x]++;
        }

        priority_queue<pair<int, int>> pq;
        for(auto x: um){
            pq.push({x.second, x.first});
            // cout<<x.first<<x.second<<endl;

        }
        
        vector<int> output;
        while(k){
            auto top = pq.top();
            pq.pop();
            // cout<<top.first<<top.second<<endl;
            output.push_back(top.second);
            k--;

        }
        return output;
        return {};
    }
};