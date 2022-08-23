// https://dev.to/vaib215/solution-must-do-pattern-problems-before-starting-dsa-striver-dsa-course-40lb

#include<iostream>
using namespace std;

void patterns_one(int n) {
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            cout<<"*";
        }
        cout<<endl;
    }
}

void patterns_two(int n) {
    for(int i=0; i<n; ++i) {
        for(int j=0; j<=i; ++j) {
            cout<<"*";
        }
        cout<<endl;
    }
}

void patterns_three(int n) {
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=i; ++j) {
            cout<<j;
        }
        cout<<endl;
    }
}

void patterns_four(int n) {
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=i; ++j) {
            cout<<i;
        }
        cout<<endl;
    }
}

void patterns_five(int n) {
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=i; ++j) {
            cout<<i;
        }
        cout<<endl;
    }
}

int main() {
    int n = 5;
    patterns_one(n);
    patterns_two(n);
    patterns_three(n);
    patterns_four(n);
}