#include<bits/stdc++.h>
using namespace std;

class Graph {
	private:
		int vertex;
		vector<int> *adj;
	public:
		Graph(int vertex) {
			this->vertex = vertex;
			adj = new vector<int>[this->vertex];
		}

		void addEdge(int u, int v) {
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		void printGraph() {

			for(int u=0; u<(this->vertex); ++u) {
				cout<<u;
				for(int v:adj[u]) {
					cout<<" --> "<<v;
				}
				cout<<endl;
			}
			cout<<endl;
		}

		// this is for vector<vector<int>>
		void printGraph2(vector<vector<int>> &arr) {
			for(auto val:arr) {
				for(int value:val) {
					cout<<value<<" ";
				}
				cout<<endl;
			}
			cout<<endl;
		}

		vector<vector<int>> convertGraph() {

			vector<vector<int>> ans(this->vertex);

			for(int i=0; i<(this->vertex); ++i) {

				int n = adj[i].size();
				vector<int>arr(n+1);

				arr[0] = i;

				for(int j=1; j<=n; ++j) {

					arr[j] = adj[i][j-1];
				}
				ans[i] = arr;
			}
			return ans;
		}
};

int main() {
	int t;
	cin>>t;

	for(int i=0; i<t; ++i) {
		int n, m;
		cin>>n>>m;
		Graph g(n);
		for(int j=0; j<m; ++j) {
			int u, v;
			cin>>u>>v;
			g.addEdge(u, v);
		}

		g.printGraph();

		cout<<"Completed"<<endl;

		vector<vector<int>>arr = g.convertGraph();

		g.printGraph2(arr);

		cout<<"Completed"<<endl;
	}
	return 0;
}


/*

5 7
0 1
0 4
1 2
1 3
1 4
2 3
3 4

*/


/*

0 
1 
2 
3 
4 

0  - > 1 - > 4
1  - > 0 - > 2 - > 3 - > 4
2  - > 1 - > 3
3  - > 1 - > 2 - > 4
4  - > 0 - > 1 - > 3


first value is vertex



0 1 4 
1 0 2 3 4 
2 1 3 
3 1 2 4 
4 0 1 3 

Complete

*/