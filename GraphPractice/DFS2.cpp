#include <bits/stdc++.h>
using namespace std;

class Graph {
	private:
		vector<vector<int>> adj;
		int vertex;
	public:
		Graph(int v) {
			this->vertex = v;
			adj.resize(vertex);
		}

		void addEdge(int u, int v) {
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		vector<vector<int>>& getGraph() {
			return adj;
		}

		void dfsUtil(vector<vector<int>> &adj, vector<int> &ans, vector<bool> &visited, int source) {
			visited[source] = true;
			ans.push_back(source);

			for(int v:adj[source]) {
				if(visited[v]==false) {
					dfsUtil(adj, ans, visited, v);
				}
			}
		}

		// this is for disconnected graph
		vector<int> dfs(vector<vector<int>> &adj) {
			int vertex = adj.size();
			vector<int>ans;
			vector<bool>visited(vertex, false);
			int count = 0;

			for(int i=0; i<vertex; ++i) {
				if(visited[i]==false) {
					++count;
					dfsUtil(adj, ans, visited, i);
				}
			}
			cout<<"Number of disconnected Graph "<<count<<"\n";
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

		vector<int> ans = g.dfs(adj);

		for(int val:ans) {
			cout<<val<<" ";
		}
		cout<<"\n";
	}
}

/*
input

2
5 7
0 1
0 4
1 2
1 3
1 4
2 3
3 4
9 6
0 1
0 2
3 4
3 5
4 5
6 7

*/