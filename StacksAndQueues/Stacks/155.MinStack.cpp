//brute

class MinStack {
public:
    MinStack() {
    }

    stack<pair<int, int>>minStack;
    
    void push(int value) {
        if ( minStack.empty() ) {
            minStack.push({value, value});
        } else{
            minStack.push({value, min(value, minStack.top().second)});
        }
    }
    
    void pop() {
        if (!minStack.empty()) {
            minStack.pop();
        } 
    }
    
    int top() {
        return minStack.top().first;
    }
    
    int getMin() {
        return minStack.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

//optimal
class MinStack {
public:
    stack<long long> st;
    long long mn;

    MinStack() {
        mn = LLONG_MAX;
    }

    void push(int value) {
        if (st.empty()) {
            st.push(value);
            mn = value;
        } 
        else if (value < mn) {
            st.push(2LL * value - mn);   
            mn = value;
        } 
        else {
            st.push(value);
        }
    }

    void pop() {
        long long topEl = st.top();
        st.pop();

        if (topEl < mn) {
            mn = 2LL * mn - topEl;
        }
    }

    int top() {
        long long topEl = st.top();

        if (topEl < mn)
            return (int)mn;

        return (int)topEl;
    }

    int getMin() {
        return (int)mn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
