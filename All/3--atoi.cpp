// leetcode 8

class Solution {
public:
    
    bool isDigit(char ch) {
        int val = ch - '0';
        if(val>=0 and val<=9) {
            return true;
        }
        return false;
    }
    
    int char2int(char ch) {
        return (ch-'0');
    }
    
    long str2num(string s) {
        int n = s.size();
        long ans = 0;
        long power = 1;
        for(int i=0; i<n; ++i) {
            ans += (char2int(s[n-i-1]) * power);
            power *= 10;
        }
        return ans;
    }
    
    int myAtoi(string s) {
        
        string str = "";
        long ans = 0;
        int n = s.size(), i = 0;
        
        // remove initial space and zero
        while(i<n) {
            if(s[i]==' ') {
                ++i;
                continue;
            }
            else {
                break;
            }
        }
        
        bool pos = true;
        
        if(i<n) {
            if(s[i]=='-') {
                pos = false;
                ++i;
            }
            else if(s[i]=='+') {
                ++i;
            }
        }
        
        // remove initial zero
        while(i<n) {
            if(s[i]=='0') {
                ++i;
                continue;
            }
            else {
                break;
            }
        }
        
        if(i>=n) {
            return ans;
        }
        
        while(i<n) {
            if(isDigit(s[i])) {
                str.push_back(s[i++]);
            }
            else {
                break;
            }
        }
        
        if(str.size()>10) {
            if(pos) {
                return INT_MAX;
            }
            else {
                return INT_MIN;
            }
        }
        
        ans = str2num(str);
        
        if(pos) {
            if(ans>INT_MAX) {
                return INT_MAX;
            }
            else {
                return ans;
            }
        }
        else {
            if(-ans<INT_MIN) {
                return INT_MIN;
            }
            else {
                return -ans;
            }
        }
    }
};