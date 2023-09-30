// Next greater element -- leetcode 503

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    stack<int> stk;
    for(int i=n-2; i>=0; --i) {
        stk.push(nums[i]);
    }
    for(int i=n-1; i>=0; --i) {
        while(!stk.empty() && stk.top()<=nums[i]) {
            stk.pop();
        }
        if(stk.empty()) {
            ans[i] = -1;
        }
        else {
            ans[i] = stk.top();
        }
        stk.push(nums[i]);
    }
    return ans;
}