class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;

        for(int i=0; i<min(k, n); i++){
            pq.push({matrix[i][0], i, 0});
        }

        int res=0;

        while(!pq.empty() && k){
            auto [sum, i, j]= pq.top();
            pq.pop();
            res=sum;

            long long nextSum;
            if(j+1<n){
                pq.push({matrix[i][j+1], i, j+1});
            }
            k--;
            
        }

        return res;


        
    }
};