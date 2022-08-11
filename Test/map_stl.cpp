#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
    map<string, int>mp;
    mp.insert({"rajdeep", 1});
    mp.insert({"raju", 2});
    mp.insert({"raja", 3});
    mp.insert({"rajdeep", 7});

    for(auto it:mp) {
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<endl;

    multimap<string, int>mm;
    mm.insert({"rajdeep", 1});
    mm.insert({"raju", 2});
    mm.insert({"raja", 3});
    mm.insert({"rajdeep", 7});

    for(auto it:mm) {
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<endl;
    return 0;
}