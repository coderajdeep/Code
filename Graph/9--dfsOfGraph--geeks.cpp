// DFS of graph
// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    int visited[V] = {0};
    queue<int>q;
    q.push(0);
    visited[0] = 1;
    vector<int> ans;
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for(int v:adj[u]) {
            if(!visited[v]) {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
    return ans;
}