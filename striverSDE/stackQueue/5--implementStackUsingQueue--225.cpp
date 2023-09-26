// Implement stack using queue -- leetcode 225

class MyStack {
private:
    queue<int> q1, q2;
    int element;
    void clearQueue(queue<int> &q) {
        while(!q.empty()) {
            q.pop();
        }
    }
public:
    // Time complexity O(n) 
    MyStack() {
        clearQueue(q1);
        clearQueue(q2);
    }
    // Time complexity O(n)
    void push(int x) {
        q2.push(x);
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    // Time complexity O(1)
    int pop() {
        element = q1.front();
        q1.pop();
        return element;
    }
    // Time complexity O(1)
    int top() {
        return q1.front();
    }
    // Time complexity O(1)
    bool empty() {
        return q1.empty();
    }
};