// Implement Minimum stack -- leetcode 155

// Time complexity O(1)
// Space complexity O(2*n)
class MinStack {
private:
    // value, min 
    stack<pair<int, int>> stk;
    pair<int, int>p;
    void clearStack() {
        while(!stk.empty()) stk.pop();
    }
public:
    MinStack() {
        clearStack();
    }
    
    void push(int val) {
        if(stk.empty()) {
            stk.push({val, val});
        }
        else {
            p = stk.top();
            stk.push({val, min(val, p.second)});
        }
    }
    
    void pop() {
        if(!stk.empty()) {
            stk.pop();
        }
    }
    
    int top() {
        if(stk.empty()) {
            return -1;
        }
        else {
            p = stk.top();
            return p.first;
        }
    }
    
    int getMin() {
        if(stk.empty()) {
            return -1;
        }
        else {
            p = stk.top();
            return p.second;
        }
    }
};

// Time complexity O(1)
// Space complexity O(n)
class MinStack {
private:
    stack<long> stk;
    long minElement, topElement;
    void clearStack() {
        while(!stk.empty()) {
            stk.pop();
        }
    }
public:
    MinStack() {
        clearStack();
        minElement = INT_MAX;
    }
    
    void push(int val) {
        if(minElement == LONG_MAX) {
            minElement = LONG_MAX;
            stk.push(val);
        }
        else if(val < minElement) {
            // ((2 * val) - minElement) < minElement
            stk.push((long)2 * val - minElement);
            minElement = val;
        }
        else {
            stk.push(val);
        }
    }
    
    void pop() {
        if(stk.empty()) {
            return;
        }
        topElement = stk.top();
        cout<<topElement<<endl;
        if(topElement < minElement) {
            minElement = ((long)2 * minElement - topElement);
        }
        stk.pop();
    }
    
    int top() {
        if(stk.empty()) {
            return -1;
        }
        topElement = stk.top();
        if(topElement < minElement) {
            return minElement;
        }
        return topElement;
    }
    
    int getMin() {
        return minElement;
    }
};