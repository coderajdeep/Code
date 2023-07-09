// https://practice.geeksforgeeks.org/problems/nth-fibonacci-number1335/1

int nthFibonacci(int n){
    if(n<=1) return n;
    int num = 1e9 + 7;
    int prev2, prev, curr;
    prev2 = 0;
    prev = 1;
    for(int i=2; i<=n; ++i) {
        curr = (prev2 + prev) % num;
        prev2 = prev;
        prev = curr;
    }
    return curr;
}