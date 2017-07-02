/*
	Nome: Lívia Almeida Barbosa
	Matricula: 2013007579
	Problema: POODLEMG - Poodle

	São lidos os numeros da entrada e feito o processamento para saber quantos "o"s a mais serao impressos.
	Se for de 0 a 6 páginas (incluso) é impresso apenas a palavra "Poodle".
	Se o numero X de paginas for de 7 a 14, são impressos X - 6 "o"s a mais na palavra.
	Acima de 14 paginas, a palavra máxima de 20 caracteres ("Poooooooooooooooodle") é exibida;

*/


#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main(void){
	int totalres , respp;
	while(1){
		cin >> totalres >> respp;
		if( totalres == 0 && respp == 0) break;
	
		int nump = totalres/respp;
		if( totalres % respp > 0) nump++;

		if (nump <= 6) cout << "Poodle" << endl;
		else{			
			nump -= 6;
			if( nump >= 15) nump = 14;	
			cout << "Poo";
			for (int i = 0; i < nump ; i++) {
				cout << "o";
			}
			cout << "dle"<< endl;
		} 
		
	}	
	return 0;
}

