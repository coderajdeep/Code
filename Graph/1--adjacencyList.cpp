// geeks
// https://practice.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1/#
// https://www.geeksforgeeks.org/graph-and-its-representations/
// https://youtu.be/bTtm2ky7I3Y?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw



class Solution {
    public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<int> adj[]) {
        // Code here
        
        if(V==0) {
            return {};
        }
        
        vector<vector<int>>ans(V);
        
        for(int i=0; i<V; ++i) {
            
            ans[i].push_back(i);
            
            for(int val:adj[i]) {
                
                ans[i].push_back(val);
            }
        }
        
        return ans;
    }
};