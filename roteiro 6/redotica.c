/*
Nome: Livia Almeida Barbosa
Matricula: 2013007579
Problema: REDOTICA - Rede ótica

O grafo não direcionado é lido e são armazenadas arestas de u para v e de v para u, sendo u e v vértices.
As arestas que não existem são inicializadas com peso 0.
Em seguida, é executado o algoritmo de Prim para recuperar a arvore geradora minima do grafo.
No algoritmo existe um vetor que armazena os pais de cada vértice, o qual é utilizado para imprimir
a arvore mínima de resposta do problema.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int minKey(int key[], int mstSet[]){
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < 100; v++)
     if (mstSet[v] == 0 && key[v] < min)
         min = key[v], min_index = v;
 
   return min_index;
}
 

int printMST(int parent[], int nVertices, int graph[100][100]){
	int i, j, resp[nVertices - 1][2];
	for ( i = 1; i < nVertices; i++){
		if( parent[i] < i ){
			resp[i-1][0] = parent[i];
			resp[i-1][1] = i;
		}else{
			resp[i-1][0] = i;
			resp[i-1][1] = parent[i];
		}
	}

	//sort
	int aux1, aux2;
	for(i = 0; i < (nVertices - 1)- 1; i++){
		for(j = i+1; j < nVertices - 1; j++){
			if(resp[i][0] > resp[j][0]){
				//troca
				aux1 = resp[i][0];	 aux2 = resp[i][1];
				resp[i][0] = resp[j][0]; resp[i][1] = resp[j][1];
				resp[j][0] = aux1; 	 resp[j][1] = aux2;
			}

		}
	}

	for(i = 0; i < (nVertices - 1); i++){
		printf("%d %d\n", resp[i][0]+1, resp[i][1]+1);
	}	

}
 
void primMST(int graph[100][100], int nVertices){
     int parent[100]; 
     int key[100];   
     int mstSet[100];  
 	int i,count, u, v;
	for(i = 0; i < 100; i++){
		key[i] = INT_MAX; 
		mstSet[i] = 0;
	}
 
     key[0] = 0;     
     parent[0] = -1; 
 
     for(count = 0; count < 100-1; count++){
        u = minKey(key, mstSet); 
        mstSet[u] = 1;

        for(v = 0; v < 100; v++)
          if (graph[u][v] && mstSet[v] == 0 && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }
 
     printMST(parent, nVertices, graph);
}

void printresposta(int resp[100][100]){
	int i, j;
	for(i = 0 ; i < 100; i++)
		for(j = 0; j < 100; j++) {
			if(resp[i][j] == 1) printf("%d %d\n", i+1, j+1);
		}
}

int main(void){
	int numTabas, nArestas;
	int i, j, u, v, p, count = 1;
	int aldeia[100][100], resp[100][100];

	while( scanf("%d %d", &numTabas, &nArestas) && numTabas){
		for(i = 0 ; i < 100; i++)
			for(j = 0; j < 100; j++) {
				aldeia[i][j] = 0;
				resp[i][j] = 0;
			}
				

		for(i = 0 ; i <  nArestas ; i++){
			scanf("%d %d %d", &u, &v, &p);
			aldeia[u - 1][v - 1] = p;
			aldeia[v - 1][u - 1] = p;
		}

		printf("Teste %d\n",count );
		primMST(aldeia, numTabas);
		printf("\n");
		count++;
	}

	return 0;
}