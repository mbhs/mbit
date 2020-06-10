#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Brush
{
    long long height;
    long long location;
};

long long currPos;
int numBrushes;
vector<Brush> brushes;

bool brushCmp(Brush b1, Brush b2){
    return b1.height < b2.height;
}

int main(){
    cin >> numBrushes >> currPos;
    currPos--;
    brushes.resize(numBrushes);

    long long currHeight;
    for(int i = 0; i < numBrushes; i++){
        cin >> currHeight;
        brushes[i] = Brush{currHeight - 1, i};
    }

    sort(brushes.begin(), brushes.end(), brushCmp);

    long long moveDist = 0;
    for(Brush b: brushes){
        moveDist += abs(b.location - currPos);
        currPos = b.location;
    }

    cout << moveDist;
}
