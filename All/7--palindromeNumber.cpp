// leetcode 9

class Solution {
public:
    
    string int2string(int num) {
        
        if(num == 0) {
            return "0";
        }
        
        string s;
        
        
        if(num<0) {
            num = -num;
            s.push_back('-');
        }
        
        while(num>0) {
            int lastDigit = num%10;
            char ch = lastDigit + '0';
            s.push_back(ch);
            num /= 10;
        }
        return s;
    }
    
    bool isPalindrome(int x) {
        
        if(x<0) {
            return false;
        }
        else if(x==0) {
            return true;
        }
        
        string s = int2string(x);
        int lo = 0, hi = s.size()-1;
        
        while(lo<hi) {
            
            if(s[lo]!=s[hi]) {
                return false;
            }
            ++lo;
            --hi;
        }
        return true;
    }
};