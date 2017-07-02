#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

using namespace std;

int minDistance(int dist[], bool sptSet[], int nVertices){
   // Initialize min value
   int min = INT_MAX, min_index;
  
   for (int v = 0; v < nVertices; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
  
   return min_index;
}

// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[500][500], int src, int nVertices, int *dist){
          // The output array.  dist[i] will hold the shortest
                      // distance from src to i
  
     bool sptSet[nVertices]; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized
  
     // Initialize all distances as INFINITE and stpSet[] as false
     for (int i = 0; i < nVertices; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
  
     // Distance of source vertex from itself is always 0
     dist[src] = 0;
  
     // Find shortest path for all vertices
     for (int count = 0; count < nVertices-1; count++)     {
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in first iteration.
       int u = minDistance(dist, sptSet, nVertices);
  
       // Mark the picked vertex as processed
       sptSet[u] = true;
  
       // Update dist value of the adjacent vertices of the picked vertex.
       for (int v = 0; v < nVertices; v++)
  
         // Update dist[v] only if is not in sptSet, there is an edge from 
         // u to v, and total weight of path from src to  v through u is 
         // smaller than current value of dist[v]
         if (!sptSet[v] && graph[u][v] != -1 && dist[u] != INT_MAX 
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }
}


int main(void){
	int ncidades, nacordos;

	while(1){
		cin >> ncidades >> nacordos;
		if (ncidades == 0 && nacordos == 0) break;

		int grafo[500][500];
		memset(grafo, -1, sizeof(grafo[0][0])*500*500);

		int a, b, t;
		for( int i =0 ; i < nacordos ; i++){
			cin >> a >> b >> t ;
			
			if(grafo[b-1][a-1] > 0 ){
				grafo[a-1][b-1] = 0;
				grafo[b-1][a-1] = 0;
			}else{
				grafo[a-1][b-1] = t;
			}
		}

		int nconsultas, o, d, distances[ncidades];
		cin >> nconsultas;

		for(int i = 0 ; i < nconsultas; i++){
			cin >> o >> d;
		
			memset(distances, -1, sizeof(distances[0])*ncidades);			
			dijkstra(grafo, o-1, ncidades, distances);

			if( distances[d-1] == INT_MAX){
				cout << "Nao e possivel entregar a carta" << endl;
			}else{
				cout << distances[d-1] << endl;
			}

		}
		cout << endl;

	}


	return 0;
}