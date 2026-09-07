class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<
            tuple<int, int, int>
        > pq;

        vector<vector<int>> res;

        int n=points.size();

        for(int i=0; i<n; i++){
            int x=points[i][0];
            int y=points[i][1];
            int dist=((y*y)+(x*x));

            pq.push({dist, x, y});
            while(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            res.push_back({get<1>(top), get<2>(top)});
        }
        return res;

        


    }
};