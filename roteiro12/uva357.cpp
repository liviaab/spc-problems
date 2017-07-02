
/*
Nome: Livia Almeida Barbosa
Matricula: 2013007579
Problema: UVA357 - Le Me Count The Ways

Antes de realizar a leitura da entrada, é realizado o calculo de quantas maneiras é possível obter
o valor x (0 <= x <= 30000), para que nao seja necessario recalcular os valores a cada entrada lida.
O índice da posicao representa o valor e o seu conteúdo, o número de maneiras de obter tal valor.
De acordo com a dica de implementação da Wiki da maratona, calcula-se de quantas maneiras é possível
obter todos os valores do intervalo inicial e, de acordo com a entrada, é impresso o respectivo numero
de maneiras.

*/


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define MAXSIZE 30002

using namespace std;

int main(void){
	long long i, j;
	int coins[5] = {1, 5, 10, 25, 50};
	unsigned long long manners[MAXSIZE] = {0};

	manners[0] = 1;
	for (i = 0 ; i < 5 ; i++){
		for(j = coins[i]; j < MAXSIZE ; j++ ){
			manners[j] += manners[ j - coins[i]];
		}
	}

	int number;
	while(cin >> number){
		if (manners[number] == 1)
            cout << "There is only 1 way to produce " << number << " cents change.\n";
        else
            cout << "There are " << manners[number] << " ways to produce " << number << " cents change.\n";

	}
	return 0;
}