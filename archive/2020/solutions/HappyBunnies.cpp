#include <iostream>

using namespace std;


int a, b;

int getNumVal(int val){
    int tot = val;
    while(val > 0){
        int currDig = val % 10;
        if(currDig == 7){
            return 0;
        }
        val /= 10;
        tot += currDig;
    }
    return tot;
}

int main(){
    cin >> a >> b;
    long long sum = 0;

    for(int i = a; i <= b; i++){
        sum += getNumVal(i);
    }
    cout << sum;
}
