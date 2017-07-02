/*
Nome: Livia Almeida Barbosa
Matricula: 2013007579
Problema: UVA 10079 - Pizza Cutting

Uma pizza com zero cortes resulta em 1 pedaço, com 2 cortes o numero máximo de pedaços é quatro. Assim, pode-se perceber que o n-ésimo corte adiciona n novos pedaços, de forma que aplicando a formula ( ( n^2 + n) / 2 ) + 1 é possível chegar no resultado final.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <iostream>
#include <math.h>
using namespace std;

int main(void){
	long long int cuts;

	cin >> cuts ;
	while (cuts >= 0 ){
		cout << (long long int) ((long long int )(cuts*cuts + cuts )/2 + 1) << endl;
		cin >> cuts;
	}
	//cout << endl;
	return 0;
}
