/*
    Nome: Livia Almeida Barbosa
    Matricula: 2013007579
    Problema: MTOTALF - Total Flow 

    O grafo a ser montado a partir da entrada é bem simples, já que já é dado o fluxo 
    a cada par de vértices. Como os vértices são representados por letras, foi criada 
    uma função que retorna um inteiro para a letra correspondente. O intervalo dos vértices
    é das letras "A-Za-z" que são convertidas para números no intervalo [0,51]. 
    Após a leitura do grafo, imprime-se o retorno do algortimo de Ford-Fulkerson, que 
    retorna o fluxo máximo do grafo desde a fonte "A" até o destino "Z".
    O caso de duas arestas com capacidades distintas entre o mesmo par de vértices é 
    tratada durante a entrada, adicionando-se a nova capacidade à existente. As capacidades 
    das arestas são inicializadas com 0.

*/


#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <queue>
using namespace std;

#define infinity INT_MAX // Infinity
#define V 	52 // Number of vertices
 
/* Returns 1 if there is a path from source 's' to sink 't' in
  residual graph. Also fills parent[] to store the path */
bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
    bool visited[V] = {0};
 
    queue <int> q;
    q.push(s);
    visited[s] = 1;
    parent[s] = -1;
 
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


int main(void) {	
	int n, i, j, c, iu, iv;
	int G[V][V];
	char u, v, b;
	
	for(i = 0; i < V ; i++)
		for(j =0 ; j < V; j++)
			G[i][j] = 0;

	scanf("%d", &n);
	scanf("%c", &b);

	for(i = 0; i < n; i++) {
		scanf("%c %c %d", &u, &v, &c);
		scanf("%c", &b);
		iu = charToInt(u);
		iv = charToInt(v);
		G[iu][iv] += c;
	} 

	printf("%d\n", fordFulkerson(G, charToInt('A'), charToInt('Z')));

	return 0;
}
