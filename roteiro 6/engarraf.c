/*Nome: Livia Almeida Barbosa
Matricula: 2013007579
Problema: ENGARRAF - Engarrafamento

O grafo da entrada é lido e armazenado em uma matriz de adjacências, direcionada.
Cada aresta tem como peso o tempo que se leva para chegar de vértice a outro. Para
os vértices que não existem, é atribuído um valor alto (INT_MAX), acima do tempo limite da restrição.
Após a leitura, o algoritmo de Dijkstra é aplicado no grafo, o qual foi modificado para retornar
o valor do tempo mínimo total que é gasto para chegar ao vértice do destino.
Caso o valor retornado seja ÍNT_MAX, é impresso -1, caso contrário é impresso o valor retornado.

*/

#include <stdio.h>
#include <limits.h>
 
int minDistance(int dist[], int sptSet[], int nVertices){
   int min = INT_MAX, min_index;
  
   for (int v = 0; v < nVertices; v++)
     if (sptSet[v] == 0 && dist[v] <= min)
         min = dist[v], min_index = v;
  
   return min_index;
}


void dijkstra(int grafo[150][150], int lInicio, int lFim, int *tFinal, int nVertices){
	int dist[150], stopSet[150];
	int i, j;

	for(i = 0; i < 150 ; i ++) {
		dist[i] = INT_MAX;
		stopSet[i] = 0;
	}

	dist[lInicio] = 0;

	for(i = 0; i < nVertices ; i++){
		int u = minDistance(dist, stopSet, nVertices);
		stopSet[u] = 1;
		for( j = 0; j < nVertices; j++){
			if( stopSet[j] == 0 && grafo[u][j] != INT_MAX && (dist[u] != INT_MAX)  && (dist[u]+grafo[u][j] < dist[j]) ){
				dist[j] = dist[u] + grafo[u][j];
			}	
		}
	}

	if( dist[lFim] != INT_MAX ) {
		*tFinal = dist[lFim];
	}
	
}

int main(void){
	int numLocais, numRuas;
	int i, j, x, y, t;
	int lInicio, lFim, tFinal;

	while( scanf("%d %d", &numLocais, &numRuas) && numLocais || numRuas){
		tFinal = INT_MAX;
		int grafo[150][150];
		for(i = 0; i < 150 ; i++){
			for(j = 0; j < 150 ; j++){
				grafo[i][j] = INT_MAX;
			}
		}
		for( i = 0; i < numRuas ; i++){
			scanf("%d %d %d", &x, &y, &t);
			grafo[x - 1][y - 1] = t;
		}

		scanf("%d %d", &lInicio, &lFim);

		dijkstra(grafo, lInicio -1, lFim -1, &tFinal, numLocais);

		(tFinal == INT_MAX )? printf("-1\n"):printf("%d\n", tFinal);
		
	}

	return 0;
}