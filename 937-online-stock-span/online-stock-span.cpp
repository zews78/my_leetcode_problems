class StockSpanner {
public:
    vector<int> stock;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans = 1;
        int n = stock.size();
        while(n){
            if(stock[n-1]<=price){
                ans++;
            }else{
                break;
            }
            n--;
        }
        stock.push_back(price);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */