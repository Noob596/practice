#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int grid[200][200];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    
    // Please write your code here.
    int ans = 0;
    for(int x = 0; x < n - 1; x++){ // 2x2 사이즈에서 하나씩 빼서 최대값 보는게 좋을듯.
        for(int y = 0; y < m - 1; y++){
            int pos_x = x;
            int pos_y = y;
            
            int temp_1 = grid[pos_x][pos_y] + grid[pos_x][pos_y+1] + grid[pos_x+1][pos_y+1];
            int temp_2 = grid[pos_x][pos_y] + grid[pos_x+1][pos_y] + grid[pos_x+1][pos_y+1];
            int temp_3 = grid[pos_x][pos_y+1] + grid[pos_x+1][pos_y+1] + grid[pos_x+1][pos_y];
            int temp_4 = grid[pos_x][pos_y] + grid[pos_x+1][pos_y] + grid[pos_x][pos_y+1];
            ans = max({ans, temp_1, temp_2, temp_3, temp_4});

        }
    }

    for(int x = 0; x < n - 2; x++){
        for(int y = 0; y < m; y++){
            int pos_x = x;
            int pos_y = y;

            int temp = grid[pos_x][pos_y] + grid[pos_x + 1][pos_y] + grid[pos_x + 2][pos_y];
            ans = max(ans, temp);
        }
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m - 2; y++) {
            int temp = grid[x][y] + grid[x][y + 1] + grid[x][y + 2];
            ans = max(ans, temp);
        }   
    }

    cout << ans;
    return 0;
}
