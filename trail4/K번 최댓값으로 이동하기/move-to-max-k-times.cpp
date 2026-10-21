#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>


using namespace std;

int n, k;
int grid[100][100];
int r, c;

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r >> c;
    r--;
    c--;

    // Please write your code here.
    pair <int, int > pos= {r, c};
    queue < pair < int, int > > q;
    
    for(int loop = 0; loop < k; loop++){
        
        q.push(pos);
        int value = grid[pos.first][pos.second];
        
        bool visited[100][100] = {0};
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int cand_val = 0; // 이동가능한 칸들중에서 가장 큰값이 담길 후보
        vector < vector < pair < int, int > > > cand_pos (101, vector < pair < int, int > > (0)); // 그후보의 위치

        while(!q.empty()){
            pair < int, int > cur_pos = q.front();
            q.pop();
            for(int i = 0; i < 4; i ++){
                pair <int, int> next_pos = {cur_pos.first + dx[i], cur_pos.second + dy[i]};
                if(next_pos.first < 0 ||
                next_pos.first >= n ||
                next_pos.second < 0 ||
                next_pos.second >= n ||
                visited[next_pos.first][next_pos.second] == 1 ||
                grid[next_pos.first][next_pos.second] >= value){
                    continue;
                }
                q.push(next_pos);
                visited[next_pos.first][next_pos.second] = 1;
                if(grid[next_pos.first][next_pos.second] >= cand_val){
                    cand_val = grid[next_pos.first][next_pos.second];
                    cand_pos[cand_val].push_back({next_pos.first, next_pos.second});
                    
                }

            }
        }
        //이제 이동완료후 포지션 저장
        // 오름차순 정렬
        if(cand_val == 0){
            cout << pos.first + 1 << " " << pos.second + 1;
            return 0;
        }
        sort(cand_pos[cand_val].begin(), cand_pos[cand_val].end());
        pos = {cand_pos[cand_val][0].first, cand_pos[cand_val][0].second};
        
    }
    cout << pos.first + 1 << " " << pos.second + 1;
    return 0;
}
