// Juggling Algorithm for right rotation

class Solution {
public:
    
    int GCD(int a, int b) {
        if(b==0)
            return a;
        return GCD(b, a%b);
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>=n)
            k = k%n;
        if(n==1 || k==0)
            return;
        int gcd = GCD(n, k);
        
        for(int i=0; i<gcd; ++i) {
            int curr = i;
            int prevValue = nums[i], currValue;
            
            while(true) {
                int index = curr+k;
                if(index>=n)
                    index = index-n;
                if(index==i) {
                    nums[index] = prevValue;
                    break;
                }
                currValue = nums[index];
                nums[index] = prevValue;
                prevValue = currValue;
                curr = index;
            }
        }
    }
};

// Reversal Algorithm using STL

class Solution {
public:
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>=n) {
            k = k%n;
        }
        if(n==1 or k==0){
            return;
        }
        
        reverse(nums.begin(), nums.end()-k);
        reverse(nums.end()-k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};


// Reversal Algorithm

class Solution {
public:
    
    void swapElement(int &a, int &b) {
        int t = a;
        a = b;
        b = t;
    }
    
    void reverseVector(vector<int>&arr, int start, int end) {
        while(start<end) {
            swapElement(arr[start++], arr[end--]);
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>=n) {
            k = k%n;
        }
        if(n==1 or k==0){
            return;
        }
        k = n-k;
        reverseVector(nums, 0, k-1);
        reverseVector(nums, k, n-1);
        reverseVector(nums, 0, n-1);
    }
};

// Reversal Algorithm

class Solution {
public:
    
    void swapElement(int &a, int &b) {
        int t = a;
        a = b;
        b = t;
    }
    
    void reverseVector(vector<int>&arr, int start, int end) {
        while(start<end) {
            swapElement(arr[start++], arr[end--]);
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>=n) {
            k = k%n;
        }
        if(n==1 or k==0){
            return;
        }
        
        reverseVector(nums, 0, n-k-1);
        reverseVector(nums, n-k, n-1);
        reverseVector(nums, 0, n-1);
    }
};