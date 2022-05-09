#include <bits/stdc++.h>
using namespace std;

class Graph {
	private:
		int vertex;
		vector<vector<int>> adj;
	public:
		Graph(int v) {
			this->vertex = v;
			adj.resize(vertex);
		}

		void addEdge(int u, int v) {
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		vector<vector<int>> getGraph() {
			return adj;
		}

		vector<int> shortestPathUnweightedGraph(vector<vector<int>> &adj, int source) {
			int v = adj.size();
			vector<int>ans(v, INT_MIN);
			vector<bool>visited(v, false);
			queue<int>q;

			q.push(source);
			ans[source] = 0;
			visited[source] = true;

			while(!q.empty()) {
				int u = q.front();
				q.pop();
				for(int v:adj[u]) {
					if(visited[v]==false) {
						q.push(v);
						visited[v] = true;
						ans[v] = ans[u] + 1;
					}
				}
			}
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
		vector<int>ans = g.shortestPathUnweightedGraph(adj, 0);

		for(int val:ans) {
			cout<<val<<" ";
		}
		cout<<"\n";
	}
}