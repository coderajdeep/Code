// Using prefix-sum
// https://practice.geeksforgeeks.org/problems/maximum-occured-integer4602/1

class Solution {
    public:
    // L and R are input array
    // maxx : maximum in R[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in L[] and R[]
    //Function to find the maximum occurred integer in all ranges.
    int maxOccured(int L[], int R[], int n, int maxx){
    
        // Your code here
        
        int arr[maxx+1] = {0};
        
        for(int i=0; i<n; ++i) {
            int start = L[i];
            int end = R[i] + 1;
            
            arr[start]++;
            arr[end]--;
        }
        
        int ansIndex = 0;
        
        for(int i=1; i<maxx; ++i) {
            arr[i] += arr[i-1];
            if(arr[ansIndex]<arr[i]) {
                ansIndex = i;
            }
        }
        
        return ansIndex;
    }
};
