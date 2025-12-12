class StockSpanner {
public:
    stack<pair<int, int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count_cns =1;
        if(st.empty()){
            st.push({price, 1});
        }else{
            while(!st.empty() && st.top().first<=price){
                auto top = st.top();
                st.pop();
                count_cns+=top.second;
            }
            st.push({price, count_cns});
        }
        
        return st.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */