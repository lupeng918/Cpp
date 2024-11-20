#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int arr[100][100] = {};
    int x = 0, y = 0, num = 1, n;
    int dir[][2] = {{-1, 1}, {1, -1}};
    int ind = 0;
    cin >> n;
    auto max_n = n * n;

    while (num <= max_n){
        arr[x][y] = num++;
        x += dir[ind][0];
        y += dir[ind][1];

        if (x < 0 && y < n){x++; ind = 1 - ind;}
        else if (y == n){x += 2; y--; ind = 1 - ind;}
        else if (y < 0 && x < n){y++; ind = 1 - ind;}
        else if (x == n){y += 2; x--; ind = 1 - ind;}
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << setw(4) << arr[i][j];
        }
        cout << endl;
    }
    return 0;
}