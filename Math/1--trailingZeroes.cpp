// leetcode 172

class Solution {
public:
    int trailingZeroes(int n) {
        if(n<5) {
            return 0;
        }
        
        int ans = 0;
        int factor = 5;
        
        while((n/factor)>0) {
            ans += (n/factor);
            factor *= 5;
        }
        return ans;
    }
};