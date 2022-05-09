// geeks
// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1/#

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool>visited(V, false);
        vector<int>ans;
        queue<int>q;
        q.push(0);
        visited[0] = true;

        // visited[i] = true means the item has been pushed into the queue
        // not it has been push_back to the ans array
        
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            
            for(int v:adj[u]) {
                if(visited[v]==false) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        return ans;
    }
};