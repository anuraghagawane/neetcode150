class MinStack {
    stack<long> st;
    long mini;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) {
            mini = val;
            st.push(0);
        }
        else {
            st.push((long)val - mini);
            if(val < mini) mini = val;
        }
    }
    
    void pop() {
        long top = st.top();
        st.pop();

        if(top < 0) mini = mini - top;
    }
    
    int top() {
        return st.top() > 0 ? st.top() + mini : mini; 
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */