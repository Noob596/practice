#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int grid[25][25];
bool visited[25][25] = {0};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

vector < int > ans (1, 0); // 인덱스 마을번호 값 사람수

void dfs(pair < int, int > pos, int &town_cnt){
    
    for(int i = 0; i < 4; i++){
        pair < int, int> next_pos = {pos.first + dx[i], pos.second + dy[i]};
        if(next_pos.first < 0 ||
        next_pos.first >= n ||
        next_pos.second < 0 ||
        next_pos.second >= n || 
        grid[next_pos.first][next_pos.second] != 1 ||
        visited[next_pos.first][next_pos.second] == true){
            continue;
        }
        grid[next_pos.first][next_pos.second] = 2;
        visited[next_pos.first][next_pos.second] = true;
        ans[town_cnt]++;
        dfs(next_pos, town_cnt);
    }
}
int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    int town_cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j= 0; j < n; j++){
            if(grid[i][j] == 1){
                town_cnt++;
                ans.push_back(0);
                ans[town_cnt]++;
                grid[i][j] = 2;
                visited[i][j] = true;
                dfs({i, j}, town_cnt);
            }
        }
    }

    cout << ans.size() - 1 << "\n";
    sort(ans.begin(), ans.end());
    for(int i = 1; i < ans.size(); i++){
        cout << ans[i] << "\n";
    }
    return 0;
}
