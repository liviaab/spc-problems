
/*
Nome: Livia Almeida Barbosa
Matricula: 2013007579
Problema: MESA - Mesa da Sra Montagny!

É feita a leitura da entrada e é montado um grafo nao direcionado em uma matriz de adjacencias. O algoritmo de busca em profundidade recefe esse grafo, visita os nós possíveis e também os colore. Essa coloração de vértices auxilia na verificação se o grafo é bipartido ou não. Se um nó estiver sendo colorido da mesma cor de um vértice vizinho direto, é atribuída uma cor não utilizada ("-1") para um deles e o algoritmo de busca em profundidade retorna. Ao final, verifica-se se um dos vértices possui a cor -1. Se possuir, o grafo não é bipartido e não é possível resolver o problema.

*/
#include <stdio.h>

#define SIM "sim"
#define NAO "nao"

int grafo[5000][5000] = {0};
int coloridos[5000]= {0};

void DepthFirstSearch( int no, int numVertices, int cor){
	int j, r1 = 1, r2, proxCor;
	
	if(coloridos[no] == 0  ) coloridos[no] = cor;

	if( cor == 2){
		proxCor = 3;
	}else{
		proxCor = 2;
	}

	for(j = 0; j < numVertices; j ++){
		if( !coloridos[j] && grafo[no][j] ){
			DepthFirstSearch( j, numVertices, proxCor);
		}
		else if( grafo[no][j] && coloridos[no] == coloridos[j]){
			coloridos[no] = -1;
			return; 
		}
	}
	return ;
}

int main(void) {
	int numConvidados, numRelacoes;
	int u, v, r,  i, j, k = 1;
	char ans[4];

	while( 1 ){
		if( scanf("%d %d", &numConvidados, &numRelacoes) == EOF ) break;

		for (i = 0; i < numRelacoes; i++){
			scanf("%d %d", &u, &v);
			grafo[u-1][v-1] = 1;
			grafo[v-1][u-1] = 1;
		}

		for(i = 0 ; i < numRelacoes ; i++){
			DepthFirstSearch(i, numConvidados, 2);
		}

		r = 1;
		for (i = 0; i < numConvidados; i++){
			for (j = 0; j < numConvidados; j++){
				grafo[i][j] = 0;
			}
			if(coloridos[i] == (-1)){
				r = 0;
			}
			coloridos[i] = 0;
		}

		(r)? printf("Instancia %d\n%s\n\n", k, SIM) : printf("Instancia %d\n%s\n\n", k, NAO);
		k++;
	}

	return 0;
}
