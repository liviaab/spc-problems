/*Nome: Livia Almeida Barbosa
Matricula: 2013007579
Problema: PONTES09 - Caminho das pontes

O grafo não direcionado é lido e armazenado em uma matriz de adjacencia. 
Sao adicionadas arestas nos dois sentidos com o peso igual ao numero de buracos presentes
na ponte. Após a leitura do grafo, é aplicado o algoritmo de caminho mínimo Dijkstra 
que retorna a distância minima até o acampamento.

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minDistance(int dist[], int sptSet[], int nVertices){
   int min = INT_MAX, min_index;
  
   for (int v = 0; v < nVertices; v++)
     if (sptSet[v] == 0 && dist[v] <= min)
         min = dist[v], min_index = v;
  
   return min_index;
}


int dijkstra(int grafo[1010][1010], int lInicio, int lFim, int nVertices){
	int dist[1010], stopSet[1010];
	int i, j;
	int pFinal = INT_MAX;

	for(i = 0; i < 1010 ; i ++) {
		dist[i] = INT_MAX;
		stopSet[i] = 0;
	}

	dist[lInicio] = 0;

	for(i = 0; i < nVertices ; i++){
		int u = minDistance(dist, stopSet, nVertices);
		stopSet[u] = 1;
		for( j = 0; j < nVertices; j++){
			if( stopSet[j] == 0 && grafo[u][j] != -1 && (dist[u] != INT_MAX)  && (dist[u]+grafo[u][j] < dist[j]) ){
				dist[j] = dist[u] + grafo[u][j];
			}	
		}
	}
	
	pFinal = dist[lFim];
	return pFinal;
}


int main(void){
	int numPilares, numPontes;
	int pontes[1010][1010];
	int i, j, u, v, p;

	scanf("%d %d", &numPilares, &numPontes);
		
	for(i = 0; i < 1010 ; i ++)
		for(j = 0 ; j < 1010 ; j++)
			pontes[i][j] = -1;


	for(i = 0; i < numPontes ; i++){
		scanf("%d %d %d", &u, &v, &p);
			pontes[u][v] = p;
			pontes[v][u] = p;
	}

	printf("%d\n",dijkstra(pontes, 0, numPilares+1, numPilares+2));
	

	return 0;
}
