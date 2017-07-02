/*
Matricula: 2013007579
Aluna: Lívia Almeida Barbosa
Problema: IMPEDIDO - Ele está impedido

OK
Solucao:

*/
#include <stdlib.h>
#include <stdio.h>
 //Compiler version g++ 4.9

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}


int main(void) {
	int atacantes, defensores; 
	int *atc_dist, *dfs_dist;
	int i, j =0;
	char saida;
	scanf("%d %d", &atacantes, &defensores);
	
	while(atacantes != 0 || defensores != 0){
		if(atacantes > 0)  atc_dist = (int*)malloc(atacantes*sizeof(int)) ;
		if(defensores > 0) dfs_dist = (int*)malloc(defensores*sizeof(int)) ;
	
		for(i=0; i<atacantes; i++){
			scanf("%d", &atc_dist[i]);
		}
		for(i=0;i<defensores; i++){
			scanf("%d", &dfs_dist[i]);
		}	

		qsort(atc_dist, atacantes, sizeof(int), cmpfunc);
		qsort(dfs_dist, defensores, sizeof(int), cmpfunc);		

		if(atacantes == 0 ){ 
			saida = 'N';
		}
		else if( defensores == 0){
			saida = 'Y';
		}
		else if( atc_dist[0] >= dfs_dist[1] || (atc_dist[0] ==  dfs_dist[0] && atc_dist[0] ==  dfs_dist[1] ) ){
			saida = 'N';
		}else{
			saida = 'Y';
		}

		printf("%c\n", saida);
		j++;
		scanf("%d %d", &atacantes, &defensores);

		if(atacantes > 0) free(atc_dist);
		if(defensores > 0) free(dfs_dist);
	}
	return 0;
 }
    
