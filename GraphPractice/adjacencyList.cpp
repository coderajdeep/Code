#include<bits/stdc++.h>
using namespace std;

class Graph {
	private:
		vector<int> *adj;
		int vertex;
	public:
		Graph(int v) {
			this->vertex = v;
			this->adj = new vector<int>[vertex];
		}

		void addEdge(int u, int v) {
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		void printGraph() {
			for(int u=0; u<vertex; ++u) {
				cout<<u<<" ";
				for(int v:adj[u]) {
					cout<<" - > "<<v;
				}
				cout<<"\n";
			}
			cout<<"\n";
		}

		void printGraph(vector<vector<int>> &arr) {
			for(auto a:arr) {
				for(int i:a) {
					cout<<i<<" ";
				}
				cout<<"\n";
			}
			cout<<"\n";
		}

		vector<vector<int>> convertGraph() {

			vector<vector<int>>ans(vertex);

			for(int i=0; i<vertex; ++i) {
				vector<int>arr(adj[i].size()+1);
				arr[0] = i;
				int n = arr.size();
				for(int j=1; j<n; ++j) {
					arr[j] = adj[i][j-1];
				}
				// ans.push_back(arr);
				ans[i] = arr;
			}
			return ans;
		}

};

int main() {
	// n --> number of vertex
	// m --> number of edge
	int n, m;
	cin>>n>>m;
	Graph g(n);

	g.printGraph();

	for(int i=0; i<m; ++i) {
		int u,v;
		cin>>u>>v;
		g.addEdge(u, v);
	}
	g.printGraph();
	vector<vector<int>>ans = g.convertGraph();
	g.printGraph(ans);
	cout<<"Complete\n";
	return 0;
}

// Why new line's are coming?

/*
1
5 7
0 1
0 4
1 2
1 3
1 4
2 3
3 4
*/