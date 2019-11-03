#include <iostream>
using namespace std;

int main() {
	string line;
	getline(cin, line);
	int n = line.size();
	int cnt = 0;
	for(int i = 0; i<n; i++){
		if(line[i] == 'a' || line[i] == 'e' || line[i] == 'i' || line[i] == 'o' || line[i] == 'u') cnt++;
		else if(line[i] == 'y' && i == n-1) cnt++;
		else if(i != n-1 && line[i] == 'y' && line[i+1] == ' ') cnt++;
	}
	cout << cnt << endl;
	return 0;
}