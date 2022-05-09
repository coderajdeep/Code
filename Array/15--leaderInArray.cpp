// https://techiedelight.com/practice/?id=IBul

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        if(n==0)
            return {};
        vector<int>ans;
        int maxValue = a[n-1];
        ans.push_back(maxValue);
        
        for(int i=n-2; i>=0; --i) {
            if(a[i]>=maxValue) {
                ans.push_back(a[i]);
                maxValue = a[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};