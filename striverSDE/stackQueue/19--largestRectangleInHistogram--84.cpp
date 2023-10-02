// Largest Rectangle in histogram -- leetcode 84

// Brute force
// Time complexity O(n^2)
// Space complexity O(1)
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int start, end, ans = 0;
    for(int i=0; i<n; ++i) {
        for(start=i; (start>=0 && heights[start]>=heights[i]); --start) {}
        for(end=i; (end<n && heights[end]>=heights[i]); ++end) {}
        ans = max(ans, (end-start-1)*heights[i]);
    }
    return ans;
}

// Using stack
// Time complexity O(n)
// Space complexity O(n)
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int prev[n];
    int next[n];
    stack<int> stk1, stk2;
    int start = 0, end = n-1, ans = 0;

    while(start<n && end>=0) {
        while(!stk1.empty() && heights[stk1.top()]>=heights[start]) {
            stk1.pop();
        }
        if(stk1.empty()) {
            prev[start] = -1;
        }
        else {
            prev[start] = stk1.top();
        }
        stk1.push(start);

        while(!stk2.empty() && heights[stk2.top()]>=heights[end]) {
            stk2.pop();
        }
        if(stk2.empty()) {
            next[end] = n;
        }
        else {
            next[end] = stk2.top();
        }
        stk2.push(end);
        ++start;
        --end;
    }
    for(int i=0; i<n; ++i) {
        ans = max(ans, ((next[i]-prev[i]-1)*heights[i]));
    }
    return ans;
}