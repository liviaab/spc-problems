/*
MARAT09 - Maratona
*/

#include <stdio.h>
#include <iostream>
#include <limits.h>

using namespace std;

int main(void){
	int npostos, distmax;
	int i, aux;

	cin >> npostos >> distmax;
	int postos[npostos];

	for(i = 0; i < npostos ; i++){
		cin >> postos[i];
	}

	if ((postos[0] > distmax) || ( 42195 - postos[i-1] > distmax  )){
		cout << "N"<< endl;
	}
	else{

		for( i = 1; i <= npostos-1 ; i++){
			if( postos[i] - postos[i-1] > distmax ){
				cout << "N"<< endl;
				return 0;
			}
		}
		cout<< "S" << endl;
	}

	return 0;
}