/*

Nome: Lívia Almeida Barbosa
Matricula: 2013007579
Problema: ENCOTEL - Encontre o telefone

É lida a string de entrada e cada caractere é processado. 
Caso seja uma das letras do alfabeto, é impresso o número correspondente. Caso contrário, 
é impresso o caractere lido (o qual pode ser um hifen ou um numero , que nao precisam ser
traduzidos).

*/

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main(void){
	string in;
	while(cin >> in){
		int i;
		for( i = 0; i < in.length() ; i++){
			( in[i] == 'A' || in[i] == 'B' || in[i] == 'C' )? cout << 2:
			( in[i] == 'D' || in[i] == 'E' || in[i] == 'F' )? cout << 3:	 
			( in[i] == 'G' || in[i] == 'H' || in[i] == 'I' )? cout << 4:
			( in[i] == 'J' || in[i] == 'K' || in[i] == 'L' )? cout << 5:
			( in[i] == 'M' || in[i] == 'N' || in[i] == 'O' )? cout << 6:
			( in[i] == 'P' || in[i] == 'Q' || in[i] == 'R' || in[i] == 'S')? cout << 7:
			( in[i] == 'T' || in[i] == 'U' || in[i] == 'V' )? cout << 8:
			( in[i] == 'W' || in[i] == 'X' || in[i] == 'Y' || in[i] == 'Z')? cout << 9:
			cout << in[i];
		}		
		cout << endl;
	}	
	return 0;
}

