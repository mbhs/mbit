#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for(int i = 0; i<n; i++){
		int x;
		cin >> x; 
		x%= 6;
		if(2<= x && x<= 4) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}