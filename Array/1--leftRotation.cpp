// Juggling Algorithm
// little bit tricky

class Solution{   
public:
    
    int GCD(int a, int b) {
        if(b==0)
            return a;
        return GCD(b, a%b);
    }

    void leftRotate(int arr[], int n, int d) {
        
        
        if(d>=n) {
            d = d%n;
        }
        
        if(n==1 or d==0) {
            return;
        }
        
        int gcd = GCD(n, d);
        
        for(int i=0; i<gcd; ++i) {
            int curr = i;
            int temp = arr[i];
            
            while(true) {
                int index = curr + d;
                if(index>=n)
                    index = index-n;
                if(index==i) {
                    break;
                }
                arr[curr] = arr[index];
                curr = index;
            }
            arr[curr] = temp;
        }
    }
};


// left Rotation
// Reversal Algorithm

class Solution{   
public:
    
    void swapValue(int &a, int &b) {
        int t = a;
        a = b;
        b = t;
    }
    
    void reverseArray(int arr[], int start, int end) {
        
        while(start<end) {
            swapValue(arr[start++], arr[end--]);
        }
        
    }

    void leftRotate(int arr[], int n, int d) {
        
        if(d>=n)
            d = d%n;
        
        if(n<=1 || d==0)
            return;
            
        reverseArray(arr, 0, d-1);
        reverseArray(arr, d, n-1);
        reverseArray(arr, 0, n-1);
    }
};

// Reversal Algorithm (using STL)
class Solution{   
public:
    void leftRotate(int arr[], int n, int d) {
        
        if(d>=n)
            d = d%n;
        
        reverse(arr, arr+d);
        reverse(arr+d, arr+n);
        reverse(arr, arr+n);
    }
};



// Juggling Algorithm
// Complete program
#include<bits/stdc++.h>
using namespace std;

int getGcd(int a, int b) {
    if(b==0)
        return a;
    return getGcd(b, a%b);
}

int main(){
	int t,n;
	cin>>t;
	while(t--){
	    
	    int n, d;
	    cin>>n>>d;
	    
	    int arr[n];
	    for(int i=0; i<n; ++i) {
	        cin>>arr[i];
	    }
	    
	    int gcd = getGcd(n , d);
	    if(d>=n) {
	        d = d%n;
	    }
	    
	    for(int i=0; i<gcd; ++i) {
	        
	        int currIndex = i;
	        int temp = arr[i];
	        
	        while(true) {
	            int k = currIndex+d;
	            if(k>=n)
	                k = k-n;
	            if(k==i)
	                break;
	            arr[currIndex] = arr[k];
	            currIndex = k;
	        }
	        arr[currIndex] = temp;
	    }
	    
	    for(int i=0; i<n; ++i) {
	        cout<<arr[i]<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}
