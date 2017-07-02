/*Nome: Livia Almeida Barbosa
Matricula: 2013007579
Problema: DESVIO - Desvio de rota

O garfo é representado por uma matriz de adjacências onde cada aresta possui um peso (pedagio) dado. 
As arestas que nao existem são iniciadas com -1.
O grafo é construído com cuidado: 
- para as cidades que estão dentro da rota de serviço, o grafo é direcionado. Isso facilita a 
parte do problema que especifica que "se em algum momento o veículo passar por uma das 
cidades que compõem a sua rota de serviço, ele deve voltar a obedecer a rota de serviço.".
As arestas entre duas cidades na rota de serviço não sequenciais não são adicionadas
- para uma cidade que está dentro da rota de serviço e uma que está fora, só é adicionada uma
aresta, da cidade de fora para a cidade de "dentro".
- para as cidades que estão fora da rota de serviço, são adicionadas arestas nas duas direções.

Após a leitura do grafo, aplica-se o algortimo de Dijkstra, que retorna o pedagio mínimo necessário
para chegar no destino.

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


int dijkstra(int grafo[300][300], int lInicio, int lFim, int nVertices){
	int dist[300], stopSet[300];
	int i, j;
	int pFinal = INT_MAX;

	for(i = 0; i < 300 ; i ++) {
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
	int numCidTotal, numEstradas, numCidRServ, nCidConserto;
	int rotas[300][300];
	int i, j, u, v, p;

	while(scanf("%d %d %d %d", &numCidTotal, &numEstradas, &numCidRServ, &nCidConserto) 
		&& numCidTotal && numEstradas && numCidRServ && nCidConserto){
		for(i = 0; i < 300 ; i ++)
			for(j = 0 ; j < 300 ; j++)
				rotas[i][j] = -1;


		for(i = 0; i < numEstradas ; i++){
			scanf("%d %d %d", &u, &v, &p);

			if( u < numCidRServ && v < numCidRServ){
				if( (u == v + 1) || (v == u + 1)){
					if( u < v)rotas[u][v] = p;
					else rotas[v][u] = p;
				}
			}
			else if( (u < numCidRServ && v >= numCidRServ) ||  (v < numCidRServ && u >= numCidRServ)){
				if( u < v)rotas[v][u] = p;
				else rotas[u][v] = p;
			}
			else{
				rotas[u][v] = p;
				rotas[v][u] = p;
			}
		}

		printf("%d\n",dijkstra(rotas, nCidConserto, numCidRServ -1, numCidTotal));
	}

	return 0;
}
