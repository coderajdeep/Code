// BFS of graph
// geeks
// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

// In BFS, whenever you insert element in queue we need to mark that visited
// We need to take visited array because otherwise it will fall into an infinite loop
// Time complexity is O(V+2E)
// Space complexity is O(3V)

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    int visited[V] = {0};
    vector<int>ans;
    queue<int>q;
    q.push(0);
    visited[0] = 1;
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for(int v:adj[u]) {
            if(!visited[v]) {
                q.push(v);
                visited[v] = 1;
            }
        }
    }
    return ans;
}