class dataArr {
    public:
    priority_queue<int> max_heap_smaller;
    priority_queue<int, vector<int>, greater<int>> min_heap_larger;
};

class MedianFinder {
private:
dataArr ds;
public:
    MedianFinder() {
        // ds = new dataArr();
    }
    
    void addNum(int num) {
        ds.max_heap_smaller.push(num);
        int s = ds.max_heap_smaller.size();
        int l = ds.min_heap_larger.size();

        if(s>0 && l>0 && ds.max_heap_smaller.top()>ds.min_heap_larger.top()){
            // switch(ds.max_heap_smaller, ds.min_heap_larger);
            int maxx = ds.max_heap_smaller.top();ds.max_heap_smaller.pop();
            ds.min_heap_larger.push(maxx);
        }

        s = ds.max_heap_smaller.size();
        l = ds.min_heap_larger.size();


        if(s>l && s-l>1){
            // transfer(ds.max_heap_smaller, ds.min_heap_larger);
            int maxx = ds.max_heap_smaller.top();
            ds.max_heap_smaller.pop();
            ds.min_heap_larger.push(maxx);

        } 
        s = ds.max_heap_smaller.size();
        l = ds.min_heap_larger.size();
        if(l>s && l-s>1){
            // transfer(ds.min_heap_larger, ds.max_heap_smaller);
            int minn = ds.min_heap_larger.top();
            ds.min_heap_larger.pop();
            ds.max_heap_smaller.push(minn);
        }

    }
    
    double findMedian() {
        int s = ds.max_heap_smaller.size();
        int l = ds.min_heap_larger.size();
        if(s==l){
            if(s==0) return 0.0;
            int maxx = ds.max_heap_smaller.top();
            int minn = ds.min_heap_larger.top();
            return ((double)maxx + minn)/2;
        }else{
            if(s>l){
                return ds.max_heap_smaller.top();
            }else{
                return ds.min_heap_larger.top();
            }
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */