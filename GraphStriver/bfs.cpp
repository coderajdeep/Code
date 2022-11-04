#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> adj;

void dfs_traversal(int source) {
	int n = adj.size();
	vector<bool> visited(n, false);
	queue<int> q;
	q.push(source);
	visited[source] = true;
	vector<int> ans;

	while(!q.empty()) {
		int u = q.front();
		q.pop();
		ans.push_back(u);
		for(int v:u) {
			if(!visited[v]) {
				visited[v] = true;
				q.push(v);
			}
		}
	}
	int size = ans.size();
	for(int i=0; i<size; ++i) cout<<ans[i]<<" ";
	cout<<endl;
}

void init() {
	adj.clear();
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		init();
		int n, m, source;
		cin>>n>>m>>source;
		adj.resize(n);
		for(int i=0; i<m; ++i) {
			int u, v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs_traversal(source);
	}
}
