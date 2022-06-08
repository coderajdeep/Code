#include<iostream>
using namespace std;
#define NUM 50
int tb[NUM][NUM];
int tb2[NUM][NUM];

void init() {
	for(int i=1; i<=NUM; ++i) {
		for(int j=1; j<=NUM; ++j) {
			tb[i][j] = 0;
		}
	}
}


int main() {
	int T;
	cin>>T;

	for(int t=1; t<=T; ++t) {
		int u, v;
		while(true) {
			cin>>u>>v;
			if(u==-1 && v==-1) {
				break;
			}
			tb[u][v] = v;
			tb[v][u] = u;
		}

		int index = 1;
		for(int i=1; i<num; ++i) {
			for(int j=1; j<num; ++j) {
				if(tb[i][j]==1) {
					tb2[i][index++] = tb[i][j]; // same as j
					// because tb[i][j] == j
				}
			}
			// 0th column will store size
			// size means number of vertices connected to vertex of i
			tb2[i][0] = --index;
		}

	}
}