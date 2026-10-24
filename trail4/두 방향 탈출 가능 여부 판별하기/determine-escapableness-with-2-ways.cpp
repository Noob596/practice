#include <iostream>

using namespace std;

int n, m;
int grid[100][100];
bool visited[100][100] = {false};
int dx[2] = {1, 0};
int dy[2] = {0, 1};
bool flag = false;

void dfs(pair < int, int > pos){
    if(pos.first == n - 1 && pos.second == m - 1){
        flag = true;
    }
    for(int i = 0; i < 2; i++){
        if(grid[pos.first + dx[i]][pos.second + dy[i]] == 0 ||
        visited[pos.first + dx[i]][pos.second + dy[i]] == true ||
        pos.first + dx[i] < 0 ||
        pos.first + dx[i] >= n ||
        pos.second + dy[i] < 0 ||
        pos.second + dy[i] >= m){
            continue;
        }
        pair < int, int> next_pos = {pos.first + dx[i], pos.second + dy[i]};
        visited[next_pos.first][next_pos.second] = true;
        dfs(next_pos);
        //visited[next_pos.first][next_pos.second] = false;
        
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    pair <int, int > pos = {0, 0};
    dfs(pos);
    if(flag){
        cout << 1;
    }
    else{
        cout << 0;
    }
    return 0;
}
