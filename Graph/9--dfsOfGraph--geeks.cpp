// DFS of graph
// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

void dfs(int source, vector<int> *adj, vector<bool> &visited, vector<int> &ans) {
    visited[source] = true;
    ans.push_back(source);
    for(int v:adj[source]) {
        if(!visited[v]) {
            dfs(v, adj, visited, ans);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> ans;
    vector<bool> visited(V, false);
    dfs(0, adj, visited, ans);
    return ans;
}