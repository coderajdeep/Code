#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n, r, D, d, x, y;
        cin>>n>>r;
        D = r*r;
        vector<pair<int, int>> stars(n);
        for(int i=0; i<n; ++i) {
            cin>>stars[i].first>>stars[i].second;
        }
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if(i!=j) {
                    x = stars[i].first - stars[j].first;
                    y = stars[i].second - stars[j].second;
                    d = x*x + y*y;
                    if(d<=D) {

                    }
                }
            }
        }
    }
}