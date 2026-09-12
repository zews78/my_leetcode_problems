class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n=nums.size();
        using Node = tuple<int, int, int>; // (value, listIdx, elemIdx)

        priority_queue<Node, vector<Node>, greater<Node>> pq;


        int maxx=INT_MIN;

        vector<int> range({INT_MIN, INT_MAX});

        for(int k=0; k<n; k++){
            pq.push({nums[k][0], 0, k});
            maxx = max(maxx, nums[k][0]);
        }
        
        

        while(!pq.empty()){
            auto [val, i, k] = pq.top();
            long long curr_range= (maxx-val); 
            long long range_range = (long long)range[1]-range[0];
            if(curr_range<range_range){
                range[1]=maxx;
                range[0]=val;
            }
            pq.pop();

            

            //push next
            if(i+1<nums[k].size()){
                pq.push({nums[k][i+1], i+1, k});
                maxx = max(maxx, nums[k][i+1]);
            }else{
                break;
            }
        }

        return range;
    }
};