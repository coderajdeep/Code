// XOR of [L,R]  -- coding ninjas
// https://www.geeksforgeeks.org/calculate-xor-1-n/
// How optimized approach works

// Time complexity O(R-L)
// Space complexity O(1)
int findXOR(int L, int R){
    int ans = 0;
    for(int i=L; i<=R; ++i) {
        ans ^= i;
    }
    return ans;
}


// Time complexity O(1)
// Space complexity O(1)
int findXOR(int L, int R){
    if(L==R) return R;

    int reminderR = (R%4), valR;
    if(reminderR==0) valR = R;
    else if(reminderR==1) valR = 1;
    else if(reminderR==2) valR = (R+1);
    else if(reminderR==3) valR = 0;
    if(L==1) return valR;
    
    int reminderL = ((L-1)%4), valL;
    if(reminderL==0) valL = (L-1);
    else if(reminderL==1) valL = 1;
    else if(reminderL==2) valL = L;
    else if(reminderL==3) valL = 0;
    return (valL^valR);
}
/*
1- Find the remainder of n by moduling it with 4. 
2- If rem = 0, then XOR will be same as n. 
3- If rem = 1, then XOR will be 1. 
4- If rem = 2, then XOR will be n+1. 
5- If rem = 3 ,then XOR will be 0.
*/