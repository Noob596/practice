#include <iostream>

using namespace std;

int N;
int grid[20][20];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    int ans = 0;
    for(int i = 0; i <= N - 3; i++){
        for(int j = 0; j <= N - 3; j++){
            pair <int, int> pos = {i, j};
            int temp_cnt = 0;
            for(int x = 0; x < 3; x++){
                for(int y = 0; y < 3; y++){
                    if(grid[pos.first + x][pos.second + y] == 1){
                        temp_cnt++;
                    }
                }
            }
            if(ans < temp_cnt){
                ans = temp_cnt;
            }

        }
    }
    cout << ans;
    return 0;
}
