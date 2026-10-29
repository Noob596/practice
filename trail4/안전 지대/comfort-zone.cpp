#include <iostream>

using namespace std;

int N, M;
int grid[50][50];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(bool visited[50][50], int k, pair < int, int > pos){
    for(int i =0; i < 4; i++){
        pair < int, int > next_pos;
        next_pos.first = pos.first + dx[i];
        next_pos.second = pos.second + dy[i];

        if(next_pos.first < 0 ||
        next_pos.first >= N ||
        next_pos.second < 0 ||
        next_pos.second >= M ||
        visited[next_pos.first][next_pos.second] == true || 
        grid[next_pos.first][next_pos.second] <= k){
            continue;
        }
        visited[next_pos.first][next_pos.second] = true;
        dfs(visited, k, next_pos);
    }
}
int main() {
    cin >> N >> M;
    int max = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
            if (grid [i][j] > max){
                max = grid[i][j];
            }
        }
    }
    int ans_k = 1;
    int ans_safe = 0;
    for(int k = 1; k < max; k++){
        int temp = 0;
        bool visited[50][50] = {{false}};

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(grid[i][j] > k && visited[i][j] == false){
                    visited[i][j] = true;
                    dfs(visited, k, {i, j});
                    temp++;
                }
                
            }
        }
        
       if(temp > ans_safe){
        ans_k = k;
        ans_safe = temp;
       }
    }

    // Please write your code here.
    cout << ans_k << " " << ans_safe;
    return 0;
}
