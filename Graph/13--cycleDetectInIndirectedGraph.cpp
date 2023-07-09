// Geeks
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

    bool bfs(int source, bool *visited, vector<int> *adj) {
        queue<pair<int, int>> q; // node, parent
        visited[source] = true;
        q.push({source, -1});
        
        while(!q.empty()) {
            pair<int, int> p = q.front();
            int parent = p.second;
            int u = p.first;
            q.pop();
            for(int v:adj[u]) {
                if(!visited[v]) {
                    visited[v] = true;
                    q.push({v, u});
                }
                else if(visited[v] && v!=p.second) return true;
                
            }
        }
        return false;
    }
    
    bool dfs(int source, int parent, int V, bool *visited, vector<int> adj[]) {
        visited[source] = true;
        for(int v:adj[source]) {
            if(!visited[v]) {
                if(dfs(v, source, V, visited, adj)) return true;
            }
            else if(parent!=v) return true; 
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        bool visited[V];
        for(int i=0; i<V; ++i) visited[i] = false;
        for(int i=0; i<V; ++i) {
            if(!visited[i] && dfs(i, -1, V, visited, adj)) return true;
        }
        return false;
    }