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

		// Graph is connected
		vector<int> bfs(vector<vector<int>> &adjMat, int source) {

			int v = adjMat.size();
			vector<bool>visited(v, false);
			vector<int>ans;

			queue<int>q;
			q.push(source);

			visited[source] = true;

			while(!q.empty()) {
				int u = q.front();
				ans.push_back(u);
				q.pop();

				for(int v:adjMat[u]) {
					if(visited[v]==false) {
						q.push(v);
						visited[v] = true;
					}
				}
			}
			return ans;
		}

		void bfsUtil(vector<vector<int>> &adjMat,vector<int> &ans, vector<bool> &visited, int source) {
			queue<int>q;
			q.push(source);
			visited[source] = true;

			while(!q.empty()) {
				int u = q.front();
				q.pop();
				ans.push_back(u);

				for(int v:adjMat[u]) {
					if(visited[v]==false) {
						visited[v] = true;
						q.push(v);
					}
				}
			}
		}

		vector<int> bfsDisconnected(vector<vector<int>> &adjMat) {
			int vertex = adjMat.size();
			vector<int>ans;
			vector<bool>visited(vertex, false);

			for(int i=0; i<vertex; ++i) {
				if(visited[i]==false) {
					bfsUtil(adjMat, ans, visited, i);
				}
			}
			return ans;
		}

		int countDisconnected(vector<vector<int>> &adjMat) {
			int vertex = adjMat.size();
			vector<int>ans;
			vector<bool>visited(vertex, false);
			int count = 0;

			for(int i=0; i<vertex; ++i) {
				if(visited[i]==false) {
					++count;
					bfsUtil(adjMat, ans, visited, i);
				}
			}
			return count;
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
		vector<int>bfs_ = g.bfs(adj, 0);
		vector<int>bfsDisconnected_ = g.bfsDisconnected(adj);
		int count = g.countDisconnected(adj);

		for(int val:bfs_) {
			cout<<val<<" ";
		}
		cout<<"\n";

		for(int val:bfsDisconnected_) {
			cout<<val<<" ";
		}
		cout<<"\n";

		cout<<count<<"\n\n";
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