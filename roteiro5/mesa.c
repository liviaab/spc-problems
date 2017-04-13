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