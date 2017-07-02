/*
    Nome: Livia Almeida Barbosa
    Matricula: 2013007579
    Problema:  10480 - Sabotage 

    As informações da entrada são processadas para serem armazenadas
    em um grado bidirecionado. O caso de duas arestas com capacidades
    distintas entre o mesmo par de vértices é tratada durante a entrada, 
    adicionando-se a nova capacidade à existente. As capacidades das arestas
    são inicializadas com 0.
    Após a leitura da representação do grafo, é aplicado um algortimo de 
    máximo fluxo e corte mínimo no grafo, que imprime o conjunto que compõe
    o corte mínimo. 

*/

#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
using namespace std;
 
#define V 200
 
/* Returns true if there is a path from source 's' to sink 't' in
  residual graph. Also fills parent[] to store the path */
int bfs(long long int rGraph[V][V], int s, int t, int parent[])
{
    bool visited[V];
    memset(visited, 0, sizeof(visited));
 
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
 
    while (!q.empty()){
        int u = q.front();
        q.pop();
 
        for (int v=0; v<V; v++){
            if (visited[v]==false && rGraph[u][v] > 0){
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
 
    // If we reached sink in BFS starting from source, then return
    // true, else false
    return (visited[t] == true);
}
 
// A DFS based function to find all reachable vertices from s.  The function
// marks visited[i] as true if i is reachable from s.  The initial values in
// visited[] must be false. We can also use BFS to find reachable vertices
void dfs(long long int rGraph[V][V], int s, bool visited[]){
    visited[s] = true;
    for (int i = 0; i < V; i++)
       if (rGraph[s][i] && !visited[i])
           dfs(rGraph, i, visited);
}
 
// Prints the minimum s-t cut
void minCut(long long int graph[V][V], int s, int t){
    int u, v;
 
    // Create a residual graph and fill the residual graph with
    // given capacities in the original graph as residual capacities
    // in residual graph
    long long int rGraph[V][V]; // rGraph[i][j] indicates residual capacity of edge i-j
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
             rGraph[u][v] = graph[u][v];
 
    int parent[V];  // This array is filled by BFS and to store path
 
    // Augment the flow while tere is path from source to sink
    while (bfs(rGraph, s, t, parent)){
        // Find minimum residual capacity of the edhes along the
        // path filled by BFS. Or we can say find the maximum flow
        // through the path found.
        long long int path_flow = LLONG_MAX;
        for (v=t; v!=s; v=parent[v]){
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
 
        // update residual capacities of the edges and reverse edges
        // along the path
        for (v=t; v != s; v=parent[v]){
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
    }
 
    // Flow is maximum now, find vertices reachable from s
    bool visited[V];
    memset(visited, false, sizeof(visited));
    dfs(rGraph, s, visited);
 
    // Print all edges that are from a reachable vertex to
    // non-reachable vertex in the original graph
    for (int i = 0; i < V; i++)
      for (int j = 0; j < V; j++)
         if (visited[i] && !visited[j] && graph[i][j])
              cout << i+1 << " " << j+1 << endl;
 
    return;
}


int main(void) {	
	int ncities, nconn, i, j ;
    long long int c1, c2, cost;
	long long int G[V][V];	
	while (1){
        cin >> ncities >> nconn;
        if(ncities == 0 && nconn == 0) break;

        for(i = 0; i < V ; i++){
            for(j =0 ; j < V; j++){
                G[i][j] = 0;
            }
        }

        for(i = 0; i < nconn; i++) {
            cin >> c1 >> c2 >> cost;
            G[c1-1][c2-1] += cost;
            G[c2-1][c1-1] += cost;
        } 

        minCut(G, 0, 1);
        cout << endl;
    }	

	return 0;
}