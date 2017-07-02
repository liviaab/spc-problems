#include <iostream>

using namespace std;

int main(void){
	int n, m;

	while(1){
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		for(int i = 1; i < m ; i++){
			if(i != m )cout << i << " ";
			else cout << i << endl;
		}
		for(int j = n; j >= m ; j--){
			if(j != m) cout << j << " ";	
			else cout << j << endl;	
		}
	}
return 0;
}
