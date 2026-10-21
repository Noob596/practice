#include <iostream>
#include <queue>

using namespace std;

int n, k;
int grid[100][100];
int r[10000], c[10000];
bool visited[100][100] = {0};

int main() {
    cin >> n >> k;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    for (int i = 0; i < k; i++) {
        cin >> r[i] >> c[i];
        r[i]--;
        c[i]--;
    }

    // Please write your code here.
    int ans = 0;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    for(int loop = 0; loop < k; loop++){
        
        pair <int, int> pos = {r[loop], c[loop]};
        queue <pair < int, int > > q;
        q.push(pos);
        visited[pos.first][pos.second] = 1;
        
        while(!q.empty()){
            pair < int, int > cur_pos = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                pair <int, int > next_pos = {cur_pos.first + dx[i], cur_pos.second + dy[i]};
                if(next_pos.first < 0 ||
                next_pos.first >= n ||
                next_pos.second < 0 ||
                next_pos.second >= n ||
                visited[next_pos.first][next_pos.second] == 1 ||
                grid[next_pos.first][next_pos.second] == 1){
                    continue;
                }
                q.push(next_pos);
                visited[next_pos.first][next_pos.second] = 1;
                
            }
        }



    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j] == 1){
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
