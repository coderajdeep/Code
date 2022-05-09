// Using Sliding Window Approach

class Solution {

public:
    int maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        if(K>N)
            return -1;
            
        int i = 0, sum = 0, ans;
        
        while(i<K) {
            sum += Arr[i++];
        }
        
        ans = sum;
        
        for(int i=K; i<N; ++i) {
            sum += (Arr[i] - Arr[i-K]);
            ans = max(sum, ans);
        }
        
        return ans;
    }
};