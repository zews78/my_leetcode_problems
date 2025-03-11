class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n= nums.size();
        // vector<int> result(n);
        priority_queue<int> pq;
        for(int i=0; i<n; i++){
            pq.push(nums[i]);
        }
        
        for(int i=1; i<n; i+=2){
            nums[i]=pq.top();
            pq.pop();
        }
        for(int i=0; i<n; i+=2){
            nums[i]=pq.top();
            pq.pop();
        }

    }
};