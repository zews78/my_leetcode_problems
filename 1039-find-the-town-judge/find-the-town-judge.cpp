class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n);
        vector<int> outdegree(n);
        for(int i=0; i<trust.size(); i++){
            int fir = trust[i][0];
            int sec = trust[i][1];
            outdegree[fir-1]++;
            indegree[sec-1]++;
        }
        for(int i=0; i<n; i++){
            if(indegree[i]==n-1 && outdegree[i]==0){
                return i+1;
            }
        }
        return -1;
    }
};