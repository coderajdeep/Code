// Tapping Rainwater -- leetcode 42

// Time complexity O(n)
// Space complexity O(n)
int trap(vector<int>& height) {
    int n = height.size();
    int prevMax[n], nextMax[n];
    prevMax[0] = nextMax[n-1] = 0;
    int start = 1, end = n-2;
    while(start<n && end>=0) {
        prevMax[start] = max(height[start-1], prevMax[start-1]);
        nextMax[end] = max(height[end+1], nextMax[end+1]);
        ++start;
        --end;
    }
    int ans = 0;
    for(int i=1; i<n-1; ++i) {
        int minHeight = min(prevMax[i], nextMax[i]);
        if(minHeight>height[i]) {
            ans += (minHeight - height[i]);
        }
    }
    return ans;
}

// Time complexity O(n)
// Space complexity O(1)
int trap(vector<int>& height) {
    int n = height.size();
    int leftMax = 0, rightMax = 0, start = 0, end = n-1, ans = 0;
    while(start < end) {
        if(height[start] <= height[end]) {
            if(height[start] >= leftMax) {
                leftMax = height[start];
            }
            else {
                ans += (leftMax - height[start]);
            }
            ++start;
        }
        else {
            if(height[end] >= rightMax) {
                rightMax = height[end];
            }
            else {
                ans += (rightMax - height[end]);
            }
            --end;
        }
    }
    return ans;
}