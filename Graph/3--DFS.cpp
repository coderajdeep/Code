// DFS - geeks

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void dfs(vector<int> adj[], int source, vector<int> &ans, vector<bool> &visited) {
        
        ans.push_back(source);
        
        visited[source] = true;
        
        for(int v:adj[source]) {
            if(visited[v]==false) {
                dfs(adj, v, ans, visited);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        if(V==0) {
            return {};
        }
        vector<bool>visited(V, false);
        vector<int>ans;
        
        for(int i=0; i<V; ++i) {
            
            if(visited[i]==false) {
                
                dfs(adj, i, ans, visited);
            }
        }
        return ans;
    }
};


// number of island - leetcode 200