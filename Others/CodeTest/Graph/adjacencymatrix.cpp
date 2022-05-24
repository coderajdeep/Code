#include <iostream>
#include <string>

using namespace std;

class Graph {
	private:
		int vertex;
		bool **adj;
	public:
		Graph(int v) {
			this->vertex = v;
			this->adj = new bool*[this->vertex];

			for(int i=0; i<this->vertex; ++i) {
				this->adj[i] = new bool[this->vertex];
				for(int j=0; j<this->vertex; ++j) {
					adj[i][j] = false;
				}
			}
		}

		// considering the given graph is undirected
		void addEdge(int u, int v) {
			this->adj[u][v] = true;
			this->adj[v][u] = true;
		}

		void removeEdge(int u, int v) {
			if(this->adj[u][v]==false) {
				cout<<"Edge not exist\n\n";
				return;
			}
			this->adj[u][v] = false;
			this->adj[v][u] = false;
		}

		void printGraph() {
			for(int i=0; i<this->vertex; ++i) {
				for(int j=0; j<this->vertex; ++j) {
					cout<<this->adj[i][j]<<" ";
				}
				cout<<"\n";
			}
			cout<<"\n";
		}
};

int main() {
	int t;
	cin>>t;

	while(t--) {
		int v;
		cin>>v;
		Graph g(v);

		g.printGraph();
		g.addEdge(0, 1);
		g.addEdge(2, 1);
		g.printGraph();
		g.removeEdge(0, 0);
		g.removeEdge(2, 1);
		g.printGraph();
	}
	return 0;
}