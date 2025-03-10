class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> pq;
        for(int i=0; i<n; i++){
            pq.push(nums[i]);
        }
        while(k-1){
            pq.pop();
            k--;
        }
        return pq.top();


        // int n= nums.size();
        // priority_queue<int, vector<int>, greater<int>> minHeap;
        // for(int i=0; i<n; i++){
        //     minHeap.push(nums[i]);
        //     if(minHeap.size()>k){
        //         minHeap.pop();
        //     }
        // }
        // return minHeap.top();
    }
};