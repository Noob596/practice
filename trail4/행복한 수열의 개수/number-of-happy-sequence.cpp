#include <iostream>

using namespace std;

int n, m;
int grid[100][100];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    if (m == 1) { // 예외먼저
        cout << 2 * n;
        return 0;
    }

    // 행 보기
    int ans = 0;
    for(int i = 0; i < n; i++){

        int target = m - 1;
        int temp_num = grid[i][0];
        for(int j = 1; j < n; j++){
            if(target == 0){
                ans++;
                break;
            }
            if(grid[i][j] == temp_num){
                target--;
                if(target == 0){
                    
                    ans++;
                    break;
                }
            }
            else if(grid[i][j] != temp_num){
                target = m - 1;
                temp_num = grid[i][j];
            }
        }
    }
    //열 보기
    for(int i = 0; i < n; i++){

        int target = m - 1;
        int temp_num = grid[0][i];
        for(int j = 1; j < n; j++){
            if(target == 0){
                ans++;
                break;
            }
            if(grid[j][i] == temp_num){
                target--;
                if(target == 0){
                    ans++;
                    break;
                }
            }
            else if(grid[j][i] != temp_num){
                target = m - 1;
                temp_num = grid[j][i];
            }
        }
    }
    cout << ans;
    // Please write your code here.

    return 0;
}
