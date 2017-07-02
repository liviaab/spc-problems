#include <iostream>
#include <math.h>

using namespace std;

int main(void){
	double taxaBr = (double) 1/90;
	double taxaGr = (double) 7/90;
	long int time;

	cin >> time;

	while(time > 0){
		cout << "Brasil "<< (int) floor(taxaBr*time)<< " x Alemanha " << (int) ceil(taxaGr*time) << endl;
		cin >> time;		
	}
}
