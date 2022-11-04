// leetcode 547
// No of provinces

// using dfs
void dfs(int source, int n, vector<vector<int>> &isConnected, vector<bool> &visited) {
    visited[source] = true;
    for(int i=0; i<n; ++i) {
        if(isConnected[source][i] && !visited[i]) {
            dfs(i, n, isConnected, visited);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected[0].size();
    vector<bool> visited(n, false);
    int count = 0;
    for(int i=0; i<n; ++i) {
        if(!visited[i]) {
            ++count;
            dfs(i, n, isConnected, visited);
        }
    }
    return count;
}

// using bfs
void bfs(int source, int n, vector<vector<int>>& isConnected, vector<bool> &visited) {
    visited[source] = true;
    queue<int> q;
    q.push(source);
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i=0; i<n; ++i) {
            if(isConnected[u][i]==1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected[0].size();
    vector<bool> visited(n, false);
    int count = 0;
    
    for(int i=0; i<n; ++i) {
        if(!visited[i]) {
            ++count;
            bfs(i, n, isConnected, visited);
        }
    }
    return count;
}