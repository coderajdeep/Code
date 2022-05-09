#include<bits/stdc++.h>
using namespace std;

class Graph {
	private:
		bool **adj;
		int vertex;
	public:
		Graph(int v) {
			this->vertex = v;
			this->adj = new bool*[vertex];

			for(int i=0; i<vertex; ++i) {
				adj[i] = new bool[vertex];
				for(int j=0; j<vertex; ++j) {
					adj[i][j] = false;
				}
			}
		}

		void addEdge(int u, int v) {
			adj[u][v] = true;
			adj[v][u] = true;
		}

		void removeEdge(int u, int v) {
			adj[u][v] = false;
			adj[v][u] = false;
		}

		void printGraph() {
			for(int i=0; i<vertex; ++i) {
				for(int j=0; j<vertex; ++j) {
					cout<<adj[i][j]<<" ";
				}
				cout<<"\n";
			}
			cout<<"\n";
		}
};

int main() {
	Graph g(7);
	g.addEdge(1, 2);
	g.addEdge(3, 5);
	g.addEdge(2, 5);
	g.addEdge(1, 0);
	g.printGraph();
	g.removeEdge(2, 5);
	g.printGraph();
	return 0;
}

/*
1
5 7
0 1
0 4
1 2
1 3
1 4
2 3
3 4
*/