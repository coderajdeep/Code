
/*

Similar problem - Next Greater Element

Sample I/O

Input  : arr[] = {2, 4, 8, 7, 7, 9, 3}
Output : 4
Left smaller   LS[] = {0, 2, 4, 4, 4, 7, 2}
Right smaller  RS[] = {0, 3, 7, 3, 3, 3, 0}
Maximum Diff of abs(LS[i] - RS[i]) = 7 - 3 = 4

*/


class Solution{
    public:
    /*You are required to complete this method */
    int findMaxDiff(int A[], int n)
    {
        //Your code here
        
        int l[n] = {0}, r[n] = {0};
        
        stack<int>s;
        s.push(A[0]);
        
        // this is for left array
        for(int i=1; i<n; ++i) {
            
            while(!s.empty() and s.top()>=A[i]) {
                s.pop();
            }
            if(s.empty()) {
                l[i] = 0;
            }
            else {
                l[i] = s.top();
            }
            s.push(A[i]);
        }
        
        // stack does not have clear method
        // s.clear();
        stack<int>S;
        S.push(A[n-1]);
        
        // this is for right array
        for(int i=n-2; i>=0; --i) {
            
            while(!S.empty() and S.top()>=A[i]) {
                S.pop();
            }
            if(S.empty()) {
                r[i] = 0;
            }
            else {
                r[i] = S.top();
            }
            S.push(A[i]);
        }
        
        int ans = 0;
        
        for(int i=0; i<n; ++i) {
            ans = max(ans, abs(l[i] - r[i]));
        }
        
        return ans;
    }
};