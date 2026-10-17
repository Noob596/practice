#include <iostream>
#include <vector>


using namespace std;

int n;
int x1[10], y1[10];
int x2[10], y2[10];

int map[201][201] = {0};


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    }

    for(int loop = 1; loop <= n; loop++){
        pair<int, int> left_down = {x1[loop - 1] + 100, y1[loop - 1] + 100};
        pair<int, int> right_top = {x2[loop - 1] + 100, y2[loop - 1] + 100};
        // 빨강은 1 파랑은 2 색칠안되면 0
    
        for(int i = left_down.first; i < right_top.first; i++){
            for(int j = left_down.second; j < right_top.second; j++){
                if(loop % 2 != 0){
                    map[i][j] = 1;
                }
                else{
                    map[i][j] = 2;
                }
                
            }
        }

    }
    int ans = 0;
    for(int i = 0; i < 201; i++){
        for(int j = 0; j < 201; j++){
            if(map[i][j] == 2){
                ans++;
            }
        }
    }

    cout << ans;
    // Please write your code here.

    return 0;
}