class Solution {
public:

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>> low; //max heap
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> high; //min heap
        vector<bool> deleted(n, false);
        vector<double> res;

        int delx=0;
        int dely=0;

        int i;
        for(i=0; i<k; i++){
            low.push({nums[i], i});
            high.push(low.top());
            low.pop();

            if(high.size()>low.size()){
                low.push(high.top());
                high.pop();
            }
        }

        auto pruneLow = [&]{
            while(!low.empty() && deleted[low.top().second]){
                low.pop();
                delx--;
            }
        };
        auto pruneHigh = [&]{
            while(!high.empty() && deleted[high.top().second]){
                high.pop();
                dely--;
            }
        };

        auto findMedian = [&] {
            int l = low.size()-delx;
            int h = high.size()-dely;

            if(l==h){
                return ((double)(low.top().first+(double)high.top().first))/2.0;
            }else{
                return (double)low.top().first;
            }
        };



        for(int i=k; i<n; i++){
            res.push_back(findMedian());
            int to_be_del = nums[i-k];
            deleted[i-k]=true;
            if(to_be_del<=low.top().first){
                delx++;
            }else{
                dely++;
            }

            //pruning
            pruneLow();

            low.push({nums[i], i});
            high.push(low.top());
            low.pop();

            pruneLow();
            pruneHigh();

            if((high.size()-dely)>(low.size()-delx)){
                low.push(high.top());
                high.pop();
                pruneLow();
                pruneHigh();

            }



        }
            res.push_back(findMedian());

        return res;
    }
};