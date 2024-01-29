class MyQueue {
public:
    stack<int> st;
    MyQueue() {
        
    }

    void popFromBottom(stack<int> &st, int &x){
        if(st.size()==1){
            int numm= st.top();
            st.pop();
            x = numm;
            return;
        }

        int top = st.top();
        st.pop();
        popFromBottom(st, x);
        st.push(top);
    }

    void peakEle(stack<int> &st, int &x){
        if(st.size()==1){
            x = st.top();
            return;
        }

        int top = st.top();
        st.pop();
        peakEle(st, x);
        st.push(top);
    }
    
    void push(int x) {
        st.push(x);
        
    }
    
    int pop() {
        int x;
        popFromBottom(st, x);
        return x;
        
    }
    
    int peek() {
        int x;
        peakEle(st,x);
        return x;
    }
    
    bool empty() {
        return st.empty();
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */