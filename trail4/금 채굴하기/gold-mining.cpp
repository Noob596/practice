#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
int grid[20][20];
int gold_cnt = 0;
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 1){
                gold_cnt++;
            }
        }
    }

    // Please write your code here.
    // k 최대값은 손해아닌만큼까지
    int ans = 0;
    for(int k = 0; (k*k + (k + 1) * (k + 1)) <= (gold_cnt * m); k++){
        for(int x = 0; x < n; x++){
            for(int y = 0; y < n; y++){  //중심점 loop  
                // 여기서부터 중심점을 기준으로 마름모 돌기
                int temp_ans = 0;

                for(int sq_x = x - k; sq_x <= x + k; sq_x++){
                    for(int sq_y = y - k; sq_y <= y + k; sq_y++){
                        // 경계 및 이동횟수 초과면 컨티뉴
                        if(sq_x < 0 ||
                        sq_y < 0 ||
                        sq_x >= n ||
                        sq_y >= n ||
                        (abs(x - sq_x) + abs(y - sq_y)) > k)
                        {
                            continue;
                        }

                        if(grid[sq_x][sq_y] == 1){
                            temp_ans++;
                        }
                    }
                }
                if(temp_ans * m >= k*k + (k+1) * (k+1)){
                    ans = max(ans, temp_ans);
                }
                if(ans == gold_cnt){
                    cout << ans;
                    return 0;
                }
            }
        }

    }
    cout << ans;

    
    return 0;
}
