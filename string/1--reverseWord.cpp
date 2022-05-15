// leetcode 151

// Using stack
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        if(n==0) return "";
        
        string st;
        stack<string> stk;
        
        for(int i=0; i<n; ++i) {
            if(s[i]!=' ') st.push_back(s[i]);
            
            else if(st.size()) {
                stk.push(st);
                st.clear();
            }
        }
        if(st.size()) {
            stk.push(st);
            st.clear();
        }
        
        while(!stk.empty()) {
            st += stk.top();
            stk.pop();
            if(!stk.empty()) st += " ";
        }
        
        return st;
    
    }
};