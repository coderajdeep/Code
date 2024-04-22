// Find Eventual Safe States -- leetcode 802
// Time complexity O(E+V)
// Space complexity O(E+V) + O(2*V)
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> adj[n];
    vector<int> indegree(n, 0);
    for(int i=0; i<n; ++i) {
        for(int node : graph[i]) {
            adj[node].push_back(i);
            indegree[i]++;
        }
    }
    queue<int> q;
    for(int i=0; i<n; ++i) {
        if(indegree[i]==0) {
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for(int v : adj[u]) {
            indegree[v]--;
            if(indegree[v]==0) {
                q.push(v);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}