#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Ship
{
    bool isDestroyed;
    long long x, y;
};

int numShips;
vector<Ship> allShips;
vector<int> shipDestroyIndices;
vector<vector<int>> closest;

Ship curr;

bool shipCmp(int s1, int s2){
    long long distSqr1 = (allShips[s1].x - curr.x) * (allShips[s1].x - curr.x) + (allShips[s1].y - curr.y) * (allShips[s1].y - curr.y);
    long long distSqr2 = (allShips[s2].x - curr.x) * (allShips[s2].x - curr.x) + (allShips[s2].y - curr.y) * (allShips[s2].y - curr.y);
    if(distSqr1 == distSqr2){
        return s1 < s2;
    }
    return distSqr1 < distSqr2;
}

int main(){
    cin >> numShips;
    allShips.resize(numShips);
    shipDestroyIndices.resize(numShips);
    closest.resize(numShips);

    for(int i = 0; i < numShips; i++){
        int shipX, shipY;
        cin >> shipX >> shipY;
        allShips[i] = Ship{false, shipX, shipY};
        shipDestroyIndices[i] = 0;
        for(int j = 0; j < numShips; j++){
            if(j == i){
                continue;
            }
            closest[i].push_back(j);
        }
    }
    
    for(int i = 0; i < numShips; i++){
        curr = allShips[i];
        sort(closest[i].begin(), closest[i].end(), shipCmp);
    }

    int output = 0;
    int numDestroyed = 0;
    while(numDestroyed < numShips - 1){
        for(int i = 0; i < numShips; i++){
            if(allShips[i].isDestroyed){
                continue;
            }
            numDestroyed++;
            curr = allShips[i];
            output = i;
            for(int j = shipDestroyIndices[i]; j < numShips - 1; j++){
                if(!allShips[closest[i][j]].isDestroyed){
                    allShips[closest[i][j]].isDestroyed = true;
                    shipDestroyIndices[i]++;
                    break;
                }
            }
        }
    }

    cout << output+1 << '\n';
}
