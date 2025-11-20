class HeapData{
public:
    priority_queue<int> low;
    priority_queue<int, vector<int>, greater<int>> high;
};


class MedianFinder {
private:
    HeapData hd;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int l = hd.low.size();
        int h = hd.high.size();
        if(l==0 || hd.low.top()>num){
            hd.low.push(num);
        }else{
            hd.high.push(num);
        }


        //rebalancing
        // l = hd.hd.low.size();
        // h = hd.high.size();
        if(hd.low.size()>hd.high.size()+1){
            hd.high.push(hd.low.top());
            hd.low.pop();
        }else if(hd.low.size()<hd.high.size()){
            hd.low.push(hd.high.top());
            hd.high.pop();
        }

    }
    
    double findMedian() {
        int l = hd.low.size();
        int h = hd.high.size();

        if(l==h){
            return (hd.low.top()+hd.high.top())/2.0;
        }else{
            return hd.low.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */