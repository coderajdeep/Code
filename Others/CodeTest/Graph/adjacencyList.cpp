#include<iostream>
#include<vector>
using namespace std;

class Graph {
	private:
		vector<int> *adj;
		int vector;
	public:
		Graph(int v) {
			this->vector = v;
			adj = new vector<int>[this->vector];
		}

		// condidering the graph is undirected
		void addEdge(int u, int v) {
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		void printGraph() {
			for(int u=0; u<this->vertex; ++u) {
				cout<<u;
				for(int v:adj[u]) {
					cout<<" --> "<<v;
				}
				cout<<"\n";
			}
		}

		vector<vector<int>> convertGraph() {
			vector<vector<int>> g(this->vertex);
			for(int i=0; i<this->vertex; ++i) {
				vector<int> temp(adj[i].size()+1);
				temp[0] = i;
				int n = temp.size();
				for(int j=1; j<n; ++j) {
					temp[j] = adj[i][j-1];
				}
				g[i] = temp;
			}
			return g;
		}

		void printGraph(vector<vector<int>> &adj) {
			for(auto it:adj) {
				for(int ele:it) {
					cout<<ele<<" ";
				}
				cout<<"\n";
			}
		} 
};

int main() {
	int t;
	cin>>t;

	while(t--) {
		
	}
}