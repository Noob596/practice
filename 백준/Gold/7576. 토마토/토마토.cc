#include <iostream>
#include <vector>

#include <queue>

using namespace std;

int main(){
    int M, N;
    cin >> M >> N;
    int prev_ripe = -1; // 초기값 -1로 설정
    int day = -1;
    bool end_flag = true;
    queue < pair <int, int> > position;

    vector < vector < int > > map (N, vector < int > (M));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
            if(map[i][j] == 0){
                end_flag = false; // 하나라도 안익은 토마토가 있으면 0이 아니므로 while문 한번 돌리기
            }
            else if(map[i][j] == 1){ // 모든 익은 토마토들을 queue에 넣고
                position.push({i, j});
            }
        }
    }


    if(end_flag == true){
        cout << 0;
        return 0;
    }

    
    
    while(!position.empty()){
        int dx[4] = {-1, 1, 0, 0}; // 상 하 좌 우
        int dy[4] = {0, 0, -1, 1};

        int temp_positionx = position.front().first;
        int temp_positiony = position.front().second;

        position.pop();

        for(int i = 0; i < 4; i++){
            if(temp_positionx + dx[i] < 0 || temp_positionx + dx[i] >= N || temp_positiony + dy[i] < 0 || temp_positiony + dy[i] >= M){ // 경계조건
                continue;
            }

            if(map[temp_positionx + dx[i]][temp_positiony+ dy[i]] == 0){
                position.push({temp_positionx + dx[i], temp_positiony + dy[i]});
                map[temp_positionx + dx[i]][temp_positiony + dy[i]] = map[temp_positionx][temp_positiony] + 1;
            }
        }
    }
    int max = -1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 0){
                cout << -1;
                return 0;
            }
            else{
                if(max < map[i][j]){
                    max = map[i][j];
                }
            }
        }
    }
    cout << max - 1;
    
    /*

    while(!end_flag){
        int curr_ripe = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(map[i][j] == 1){
                    curr_ripe++;
                }
            }
        } // 익은 토마토의 개수

        if(curr_ripe == prev_ripe){
            //종료
            end_flag = true;
            break;

        }
        
        prev_ripe = curr_ripe;
        

        // bfs
        int dx[4] = {-1, 1, 0, 0}; // 상 하 좌 우
        int dy[4] = {0, 0, -1, 1};

        // 익지 않은 토마토를 찾기
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(map[i][j] == 1){ // 맵을 돌다가 익은 토마토면
                    for(int k = 0; k < 4; k++){ // 익은 토마토 이웃에 안익은 토마토들을 queu에 push
                        
                        if(i + dx[k] < 0 || i + dx[k] >= N || j + dy[k] < 0 || j + dy[k] >= M){ // 경계조건
                            continue;
                        }

                        if(map[i + dx[k]][j + dy[k]] == 0){
                            position.push({i + dx[k], j + dy[k]});
                        }
                    }
                }
            }
        }

        while(!position.empty()){
            map[position.front().first][position.front().second] = 1;
            position.pop();
        }
        day++;

    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 0){
                cout << -1;
                return 0;
            }
        }
    }

    cout << day;
    return 0;
    // 다 돌았는데도 안익은 토마토가 있으면 -1출력
    */

}