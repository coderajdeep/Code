#include<iostream>
#include<vector>
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

		bool isCycleExist(vector<vector<int>> &adj, vector<bool> &visited, int source, int parent) {
			visited[source] = true;
			for(int v:adj[source]) {
				if(visited[v]==false and isCycleExist(adj, visited, v, source)) {
					return true;
				}
				else if(v!=parent) return true;
			}
			return false;
		}

		bool DFS(vector<vector<int>> &adj) {
			int v = adj.size();
			vector<bool> visited(v, false);
			return isCycleExist(adj, visited, 0, -1);
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
		cout<<g.DFS(adj)<<endl;
	}
	return 0;
}