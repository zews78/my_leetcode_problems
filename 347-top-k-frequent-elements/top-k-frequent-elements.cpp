class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;
        for(int i=0; i<n; i++){
            map[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(auto x: map){
            minHeap.push({x.second, x.first});
            if(minHeap.size()> k){
                minHeap.pop();
            }
        }
        vector<int> output;

        while(!minHeap.empty()){
            pair<int, int> top = minHeap.top();
            output.push_back(top.second);
            minHeap.pop();
        }
        return output;
    }
};