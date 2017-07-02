/*
    Nome: Livia Almeida Barbosa
    Matricula: 2013007579
    Problema: 820 - Internet Bandwidth

    O grafo que representa o problema é bidirecionado e, caso exista mais de uma aresta ligando
    o mesmo par de vértice, as capacidades são somadas. Para converter os "nomes" dos vértices de 
    letras para numeros inteiros, foi desenvolvida uma função que retorna um inteiro entre 0-25 e 26-51
    para as letras nos intervalos A-Z e a-z, respectivamente.
    Após a leitura do grafo, é aplicado o algoritmo de Ford-Fulkerson para retornar o fluxo maximo
    entre o par de vértices desejado.
*/

#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
using namespace std;

#define infinity INT_MAX // Infinity
// Number of vertices in given graph
#define V 	100 // Number of nodes
 
/* Returns 1 if there is a path from source 's' to sink 't' in
  residual graph. Also fills parent[] to store the path */
bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
    // Create a visited array and mark all vertices as not visited
    bool visited[V] = {0};

    // Create a queue, enqueue source vertex and mark source vertex
    // as visited
    queue <int> q;
    q.push(s);
    visited[s] = 1;
    parent[s] = -1;
 
    // Standard BFS Loop
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
 
        for (int v=0; v<V; v++)
        {
            if (visited[v]==0 && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = 1;
            }
        }
    }
 
    // If we reached sink in BFS starting from source, then return
    // 1, else 0
    return (visited[t] == 1);
}
 
// Returns the maximum flow from s to t in the given graph
int fordFulkerson(int graph[V][V], int s, int t)
{
    int u, v;
 
    // Create a residual graph and fill the residual graph with
    // given capacities in the original graph as residual capacities
    // in residual graph
    int rGraph[V][V]; // Residual graph where rGraph[i][j] indicates 
                     // residual capacity of edge from i to j (if there
                     // is an edge. If rGraph[i][j] is 0, then there is not)  
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
             rGraph[u][v] = graph[u][v];
 
    int parent[V];  // This array is filled by BFS and to store path
 
    int max_flow = 0;  // There is no flow initially
 
    // Augment the flow while tere is path from source to sink
    while (bfs(rGraph, s, t, parent))
    {
        // Find minimum residual capacity of the edges along the
        // path filled by BFS. Or we can say find the maximum flow
        // through the path found.
        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
 
        // update residual capacities of the edges and reverse edges
        // along the path
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
 
        // Add path flow to overall flow
        max_flow += path_flow;
    }
 
    // Return the overall flow
    return max_flow;
}
//Char to int
int charToInt(char a){
	int i = a;
	if( i >= 97 ){
		return i - 71;
	}
	return i-65;
}

//n = num of nodes
int main(void) {	
	int n, i, j, c, iu, iv;
    int source, sink, narcs, u, v;
	int G[V][V], net = 0;
	char b;
	
	while (1){
        scanf("%d", &n);
        scanf("%c", &b);
        // cin >> n;
        if(n == 0) break;

        for(i = 0; i < V ; i++)
            for(j =0 ; j < V; j++)
                G[i][j] = 0;

        // cin >> source, sink, narcs;
        scanf("%d %d %d", &source, &sink, &narcs);
        scanf("%c", &b);

        for(i = 0; i < narcs; i++) {
            scanf("%d %d %d", &u, &v, &c);
            scanf("%c", &b);
            // cin >> u, v, c;
            G[u-1][v-1] += c;
            G[v-1][u-1] += c;
        } 
        printf("Network %d\n", ++net);
        printf("The bandwidth is %d.\n\n", fordFulkerson(G, source-1, sink-1));
    }	

	return 0;
}
