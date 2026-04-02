#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void group_mark(vector < vector < int > >& map, pair <int, int >& posit, int row, int col){
    int dx[4] = {0, 0, -1, 1}; // 상하좌우 
    int dy[4] = {1, -1, 0, 0};

    queue < pair < int, int > > q; // bfs돌릴 큐를 만들고
    q.push(posit); // 첨에 큐에 넣고

    while(!q.empty()){ // 큐가 빌때까지
        int curr_posx = q.front().first;
        int curr_posy = q.front().second;
        map[curr_posx][curr_posy] = 0; // 현재 포지션을 0으로 만들고
        q.pop();

        for(int i = 0; i < 4; i++){ // 상하좌우를 탐색한다
            int next_posx = curr_posx + dx[i];
            int next_posy = curr_posy + dy[i];

            // 경계조건

            if(next_posx < 0 || next_posx >= row || next_posy < 0 || next_posy >= col){
                continue;
            }

            if(map[next_posx][next_posy] == -2){ // 상하좌우에 풀이 있으면
                map[next_posx][next_posy] = 0; // 0으로 바꾸고
                q.push({next_posx, next_posy}); // 큐에 넣고 반복
            }

        }

    }
}

int main(){
    int r, c;
    cin >> r;
    cin >> c;

    vector < vector < int > > graph (r, vector < int > (c, 0)); // 2차원 맵을 만들고

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            char tmp;
            cin >> tmp;
            if(tmp == '.'){ // . 이면 -1로
                graph[i][j] = -1;
            }
            else if(tmp == '#'){ // #이면 -2로 저장한다.
                graph[i][j] = -2;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[i].size(); j++){
            if(graph[i][j] == -2){
                pair < int, int > position = {i, j};
                group_mark(graph, position, r, c); // 이걸 한번 돌리면 인접한 풀들이 모두 그룹 마킹이 되고
                ans++; // 풀을 하나 +1한다
            }
        }
    }
    cout << ans;
    /*
    for(int i = 0 ; i < graph.size(); i++){
        for(int j = 0; j < graph[i].size(); j++){
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
    */

    


}