#include<bits/stdc++.h>
using namespace std;

class Graph {
	private:
		int vertex;
		vector<vector<int>> adj;
	public:
		Graph(int v) {
			this->vertex = v;
			this->adj.resize(vertex);
		}

		void addEdge(int u, int v) {
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		vector<vector<int>> getGraph() {
			return adj;
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

		// void dfsUtil(vector<vector<int>> &adj, vector<int> &ans, vector<bool> &visited, int source) {
		// 	// this if condition is not required
		// 	if(visited[source]==false) {
		// 		ans.push_back(source);
		// 		visited[source] = true;
		// 	}
		// 	for(int v:adj[source]) {
		// 		if(visited[v]==false) {
		// 			dfsUtil(adj, ans, visited, v);
		// 		}
		// 	}
		// }

		void dfsUtil(vector<vector<int>> &adj, vector<int> &ans, vector<bool> &visited, int source) {
			visited[source] = true;
			ans.push_back(source);

			for(int v:adj[source]) {
				if(visited[v]==false) {
					dfsUtil(adj, ans, visited, v);
				}
			}
		}

		vector<int> dfs(vector<vector<int>> &adj, int source) {
			int v = adj.size();
			vector<int> ans;
			vector<bool> visited(v, false);

			dfsUtil(adj, ans, visited, source);

			return ans;
		}
};

int main() {
	int t;
	cin>>t;

	while(t--) {
		int n, m;
		cin>>n>>m;
		Graph g(n);
		for(int i=0; i<m; ++i) {
			int u, v;
			cin>>u>>v;
			g.addEdge(u, v);
		}

		vector<vector<int>> adj = g.getGraph();
		// g.printGraph(adj);

		vector<int> ans = g.dfs(adj, 0);

		for(int val:ans) {
			cout<<val<<" ";
		}
		cout<<"\n";
	}
}

/*
input

3
5 7
0 1
0 4
1 2
1 3
1 4
2 3
3 4
7 6
0 1
0 4
1 2
2 3
4 5
4 6
7 6
0 1
1 2
2 3
0 4
4 5
4 6

*/