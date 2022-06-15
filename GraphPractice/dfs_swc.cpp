#include<iostream>
using namespace std;
#define NUM 50
int tb[NUM][NUM];
int tb2[NUM][NUM];
bool visited[NUM];

void init(int n) {
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			tb[i][j] = 0;
		}
	}

	for(int i=1; i<=n; ++i) visited[i] = false;
}

void dfs(int s) {
	cout<<s<<" ";
	visited[s] = true;
	int size = tb2[s][0];
	for(int i=1; i<=size; ++i) {
		int v = tb2[s][i];
		if(!visited[v]) {
			dfs(v);
		}
	}
}


int main() {
	int T;
	cin>>T;

	for(int t=1; t<=T; ++t) {
		int u, v, n;
		cin>>n;
		init(n);
		while(true) {
			cin>>u>>v;
			if(u==-1 && v==-1) {
				break;
			}
			tb[u][v] = v;
			tb[v][u] = u;
		}

		
		for(int i=1; i<=n; ++i) {
			int index = 0;
			for(int j=1; j<=n; ++j) {
				if(tb[i][j]!=0) {
					tb2[i][++index] = tb[i][j]; // same as j
					// because tb[i][j] == j
				}
			}
			// 0th column will store size(max index)
			// size means number of vertices connected to vertex of i
			tb2[i][0] = index;
			// tb2 --> similar to adjacency matrix
		}

		cout<<"#"<<t<<" ";
		dfs(1);
		cout<<endl;

	}
	return 0;
}

/*

1
5
1 2
2 3
4 3
3 4
4 5
1 5
-1 -1

*/