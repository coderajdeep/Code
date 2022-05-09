#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int ans[3] = {INT_MIN, INT_MIN, INT_MIN};
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; ++i) {
            cin>>arr[i];
        }

        bool flag = false;

        for(int i=0; i<n; ++i) {

            if(ans[0]<arr[i]) {
                ans[2] = ans[1];
                ans[1] = ans[0];
                ans[0] = arr[i];
            }

            else if(ans[1]<arr[i]) {
                if(ans[0]==arr[i]) {
                    continue;
                }
                ans[2] = ans[1];
                ans[1] = arr[i];
            }

            else if(ans[2]<arr[i]) {
                if(ans[0]==arr[i] or ans[1]==arr[i]) {
                    continue;
                }
                ans[2] = arr[i];
            }

            if(arr[i]==INT_MIN) {
                flag = true;
            }
        }

        if(flag) {
            if(ans[2]==ans[1] or ans[1]==ans[0]) {
                cout<<ans[0]<<"\n";
            }
            else {
                cout<<ans[2]<<"\n";
            }
        }
        else {
            if(ans[2]==INT_MIN) {
                cout<<ans[0]<<"\n";
            }
            else {
                cout<<ans[2]<<"\n";
            }
        }

        // if(ans[2]==INT_MIN) {
        //         cout<<ans[0]<<"\n";
        //     }
        //     else {
        //         cout<<ans[2]<<"\n";
        //     }
    }
    return 0;
}

// -2147483648