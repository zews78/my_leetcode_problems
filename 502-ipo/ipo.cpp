class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        int n=profits.size();
        vector<pair<int,int>> projects;
        for(int i=0; i<n; i++){
            projects.push_back({capital[i], profits[i]});
        }
        sort(projects.begin(), projects.end());

        priority_queue<pair<int, int>> max_heap;


        int idx=0;
        for(int i=0; i<k; i++){
            
            while(idx<n && projects[idx].first<=w){//check affordable
                max_heap.push({projects[idx].second, idx});
                idx++;
            }

            if(max_heap.empty()){
                break;
            }else{
                w+=max_heap.top().first;
                max_heap.pop();
            }


        }
        return w;
    }
};