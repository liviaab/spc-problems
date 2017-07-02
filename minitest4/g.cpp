// A C++ program to find bridges in a given undirected graph
#include<iostream>
#include <list>
#define NIL -1
using namespace std;
 
// A class that represents an undirected graph
class Graph{
		int V; 
		list<int> *adj;    // A dynamic array of adjacency lists

		void bridgeUtil(int v, bool visited[], int disc[], int low[], int parent[]);
	public:
		int npontes;	    
		Graph(int V);   // Constructor
		void addEdge(int v, int w); 
		void bridge();   
};
 
Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
    this->npontes = 0;
}
 
void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);  // Note: the graph is undirected
}
 
// A recursive function that finds and prints bridges using
// DFS traversal
// u --> The vertex to be visited next
// visited[] --> keeps tract of visited vertices
// disc[] --> Stores discovery times of visited vertices
// parent[] --> Stores parent vertices in DFS tree
void Graph::bridgeUtil(int u, bool visited[], int disc[], int low[], int parent[]){
    static int time = 0; 
    visited[u] = true;
    disc[u] = low[u] = ++time;
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i){
        int v = *i;  
 
        if (!visited[v]){
            parent[v] = u;
            bridgeUtil(v, visited, disc, low, parent);
            low[u]  = min(low[u], low[v]);
 
            if (low[v] > disc[u])
              //cout << u <<" " << v << endl;
		this->npontes++;
		
        }
 
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}
 
void Graph::bridge(){
    bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];
 
    // Initialize parent and visited arrays
    for (int i = 0; i < V; i++)
    {
        parent[i] = NIL;
        visited[i] = false;
    }
 
    // Call the recursive helper function to find Bridges
    // in DFS tree rooted with vertex 'i'
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            bridgeUtil(i, visited, disc, low, parent);
}
 

int main(){
	int cidades, pontes, x, y, i;
	while(cin >> cidades>> pontes){
		Graph g(cidades);
		for(i = 0; i < pontes ; i++){
			cin >> x >> y;
			g.addEdge(x-1, y-1);
		}
	    g.bridge();
	    cout << g.npontes << endl;
	}
 
    return 0;
}
