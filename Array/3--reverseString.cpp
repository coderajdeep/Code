// Iterative method

string reverseWord(string str){
    
  //Your code here
  int l = 0, r = str.size() - 1;
  while(l<r) {
      swap(str[l++], str[r--]);
  }
  return str;
}


// Recursive method

void solve(string &s, int l, int r) {
    if(l>=r)
        return;
    swap(s[l++], s[r--]);
    solve(s, l, r);
}

string reverseWord(string str){
    
  //Your code here
  solve(str, 0, str.size()-1);
  return str;
}




// recursive method

void swapChar(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

void reverseWordUtil(string &str, int start, int end) {
    if(start>=end)
        return;
    swapChar(str[start], str[end]);
    reverseWordUtil(str, start+1, end-1);
}


string reverseWord(string str){
    
    int n = str.size();
    if(n<=1)
        return str;
        
    reverseWordUtil(str, 0, n-1);
    
    return str;
}