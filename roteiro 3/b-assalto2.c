/*
Nome: Lívia Almeida Barbosa
Matricula: 2013007579
Problema: ASSALTMG - Assalto ao banco central

Solucao: Durante a leitura da entrada, as chaves são transformadas em um bitmask e é feito um 
or com as chaves anteriores do respectivo diretor. Após a leitura, chame-se a função que testa
todas as combinacoes de diretores em um grupo e, o que tiver menos diretores com a maior quantidade
de chaves diferentes e necessarias para abrir o banco, é retornado. 
As combinacoes de grupo sao "calculadas" tambem por um bitmask, ja que as combinaçoes de diretores
pode ter 2^ (numdiretores) possibilidades. 

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int testAll(int empresarios[], int nempr, int nchvs){	
	int num_sequestros = 999, num_seq_aux;
	int chave_acc = 0;
	int i,j,k;
	int limite =(int) pow(2, nempr);
	for( i = 1; i <= limite; i++){
		k = i;
		num_seq_aux = 0;
		chave_acc = 0;

		for(j = 0; j < nempr; j++, k >>= 1){
			if( k & 1){
				chave_acc |= empresarios[j];
				num_seq_aux++;
				if( num_seq_aux >= num_sequestros) break;
			}
		}

		if( __builtin_popcount(chave_acc) >= nchvs && num_seq_aux < num_sequestros){
			num_sequestros = num_seq_aux;
		}
	}
	return num_sequestros;
}

int main(void){
	int casosteste, chaves_pabrir, ndiretores, nchvs;
	int i, j, k, aux, chav_acc;
	

	scanf("%d", &casosteste);
	while( casosteste > 0){
		scanf("%d %d", &chaves_pabrir, &ndiretores);


		int empresarios[20];		
		for(i = 0 ; i < ndiretores; i++) empresarios[i] = 0;
		// Le chaves e guarda bitmask
		for( i = 0 ; i < ndiretores; i ++){
			scanf("%d", &nchvs);
			aux = 0;
			chav_acc = 0;

			for(j = 0; j < nchvs ; j++){
				scanf("%d", &aux );
				empresarios[i] |=  1 <<  aux ; 
			}
		}

		if( chaves_pabrir == 0 ){
			printf("0\n");
			casosteste--;
			continue;
		}
		//testa todas as possibilidades
		int r = testAll(empresarios, ndiretores, chaves_pabrir);
		
		if( r == 999 ) printf("Desastre!\n");
		else printf("%d\n", r );

		
		casosteste--;
	}
	return 0;
}