#include <iostream>
using namespace std;
 
int main () {
	int W, H, curX, curY;
	cin >> W >> H >> curX >> curY;
	int N;
	cin >> N;
	
	int moves = 0;
	while (N--) {
		int nxtX, nxtY;
		cin >> nxtX >> nxtY;
		int Xdist = abs(nxtX - curX), Ydist = abs(nxtY - curY);
		if (Xdist == 0 || Ydist == 0 || Xdist == Ydist) moves++;
		else moves += 2;
		curX = nxtX, curY = nxtY;
	}
 
	cout << moves << endl;
}