class Solution {
public:
    int nthUglyNumber(int n) {
        unordered_map<long, int> um;
        vector<long> ugly;

        //min heap;
        priority_queue<long, vector<long>, greater<long>> pq;

        pq.push(1);
        um[0]++;

        // int i=0;
        while(!pq.empty() && ugly.size()<n){
            long top = pq.top();
            pq.pop();

            //check visited and push
            if(!um.count(top)){
                pq.push(top*2);
                pq.push(top*3);
                pq.push(top*5);

                ugly.push_back(top);
                um[top]++;
            }
            
        }

        return ugly[n-1];
        // return 0;

    }
};