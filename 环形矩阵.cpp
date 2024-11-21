#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int arr[100][100] = {};
    // x,y 表示数组元素的索引，num 表示要填写的数字，n 表示数组的宽度
    int x = 0, y = 0, num = 1, n;
    // 数组 dir 保存了 4 个数组，分别代表向右、下、左、上行走时 x 和 y 索引的增量
    int dir[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int ind = 0; // ind 当做索引来获取不同方向的增量
    cin >> n;
    //把填写过数字的行和列想象成走过的道路，up/down/left/right 分别代表上下左右已走路程的行列索引
    int left = 0, up = 0, right = n - 1, down = n - 1;
    // max_n 为所填数字的最大值
    int max_n = n * n;
    //循环填写数字，直到填写到最大数字后停止
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