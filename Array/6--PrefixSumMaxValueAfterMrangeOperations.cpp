// Using prefix sum

int findMax(int n, int m, int a[], int b[], int k[])
	{
	    long long arr[n+1]={0};
	    
	    for(int i=0; i<m; ++i) {
	        int A = a[i];
	        int B = b[i];
	        int K = k[i];
	        
	        arr[A] += K;
	        arr[B+1] -= K;
	    }
	    
	    long long ans = arr[0];
	    
	    for(int i=1; i<n; ++i) {
	        arr[i] += arr[i-1];
	        ans = max(ans, arr[i]);
	    }
	    
	    return ans;
	    
	}