#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int arr[100][100] = {};
    // x,y 表示数组元素的索引，num 表示要填写的数字，n 表示数组的宽度
    int x = 0, y = 0, num = 1, n;
    int dir[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int ind = 0;
    cin >> n;
    int left = 0, up = 0, right = n - 1, down = n - 1;
    int max_n = n * n;

    while (num <= max_n){
        arr[x][y] = num++;
        x += dir[ind][0];
        y += dir[ind][1];

        if (y > right){
            up++; y--; x++;
            ind = (ind + 1) % 4;
        } else if (x > down){
            right--; x--; y--;
            ind = (ind + 1) % 4;
        } else if (y < left){
            down--; y++; x--;
            ind = (ind + 1) % 4;
        } else if (x < up){
            left++; x++; y++;
            ind = (ind + 1) % 4;
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << setw(4) << arr[i][j];
        }
        cout << endl;
    }
    return 0;
}