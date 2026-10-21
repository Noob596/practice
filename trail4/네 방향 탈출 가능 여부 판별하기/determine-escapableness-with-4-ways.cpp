#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
// int a[100][100];
bool visited[100][100];
queue < pair<int, int> > q;

int main() {
    cin >> n >> m;
    vector < vector < int > > a (n, vector < int > (m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // Please write your code here.
    
    q.push({0, 0});
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    while(!q.empty()){
        int pos_x = q.front().first;
        int pos_y = q.front().second;
        
        q.pop();
        if(pos_x == n - 1 && pos_y == m - 1){
            cout << 1;
            return 0;
        }
        for(int i = 0; i < 4; i++){
            pair < int, int > next_pos = {pos_x + dx[i], pos_y + dy[i]};
            if(next_pos.first < 0 ||
            next_pos.first >= n ||
            next_pos.second < 0 ||
            next_pos.second >= m ||
            visited[next_pos.first][next_pos.second] == 1 ||
            a[next_pos.first][next_pos.second] == 0){
                continue;
            }
            
            q.push({next_pos.first, next_pos.second});
            visited[next_pos.first][next_pos.second] = 1;

            

        }


    }
    cout << 0;


    return 0;

}
