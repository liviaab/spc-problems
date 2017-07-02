#include <iostream>
#include <string>
using namespace std;

int main(void){
	string dna;
	string resist;
	
	while(cin >> dna >> resist){		
		if (dna.find(resist) != string::npos) {
			cout << "Resistente" << endl;
		}else{
			cout << "Nao resistente" << endl;
		} 			
	}
	return 0;
}
