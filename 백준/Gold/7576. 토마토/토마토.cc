#include <iostream>
#include <vector>

#include <queue>

using namespace std;

int main(){
    int M, N;
    cin >> M >> N;
    
    /* int prev_ripe = -1; // 
    
    int day = -1; 잘못 생각해서 필요없던거 */ 
    
    bool end_flag = true; // 맨처음에 0 출력을 위한 flag
    queue < pair <int, int> > position; // 좌표는 페어로 큐로 만들고

    vector < vector < int > > map (N, vector < int > (M)); // n * m 사이즈 2차원 배열 만들고
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
            if(map[i][j] == 0){
                end_flag = false; // 하나라도 안익은 토마토가 있다 == 0일을 출력하지 않는다!
            }
            else if(map[i][j] == 1){ // 이따가 bfs를 돌리기 위해 먼저 익은 토마토들을 큐에 다 때려넣고
                position.push({i, j});
            }
        }
    }


    if(end_flag == true){ // 위에서 안익은 토마토가 발견되지 않앗으면 플래그는 트루일거임
        cout << 0;
        return 0;
    }

    
    
    while(!position.empty()){ // bfs
        int dx[4] = {-1, 1, 0, 0}; // 상 하 좌 우
        int dy[4] = {0, 0, -1, 1};

        int temp_positionx = position.front().first;
        int temp_positiony = position.front().second;

        position.pop();
        // bfs 돌리는중
        
        for(int i = 0; i < 4; i++){
            if(temp_positionx + dx[i] < 0 || temp_positionx + dx[i] >= N || temp_positiony + dy[i] < 0 || temp_positiony + dy[i] >= M){ // 경계조건
                continue;
            } // 경계조건

            if(map[temp_positionx + dx[i]][temp_positiony+ dy[i]] == 0){ // 만약 다음 포지션이 안익은 토마토면
                position.push({temp_positionx + dx[i], temp_positiony + dy[i]}); // 큐에 쳐넣고
                map[temp_positionx + dx[i]][temp_positiony + dy[i]] = map[temp_positionx][temp_positiony] + 1;
            } // 이게 중요 distance로 생각해서 현재 값에 +1 한 값을 넣어놓는다
        }
        
        // 이걸 큐가 빌때까지 돌리면 끝
    }
    int max = -1; // 그래서 총 걸린 일수 = 맵에 있는 숫자중 가장 큰거. max의 초기값은 -1을 줘놓고
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 0){ // 만약에 다돌았는데도 안익은 토마토가 잇으면 이건 불가능한거니까
                cout << -1; // -1출력하고 끝냄
                return 0;
            }
            else{
                if(max < map[i][j]){ // 맥스값을 찾고
                    max = map[i][j];
                }
            }
        }
    }
    cout << max - 1; // 정답은 맥스에 -1을 한 값이다. 왜냐면 시작은 0일차부터 하는데 세는거는 1부터 세니까 맥스값은 내가 우너하는값에 +1이 된 값이기 때문이다람쥐
    
    
    
    // 이밑에는 삽질했던 내용이다
    // 내가 생각했던거 : 매번 맵을 훑으면서 다음날 익을 토마토들을 큐에 넣고, 익은 토마토 수를 세놓는다
    // 그리고 맵을 훑을때 마다 day++을 한다.
    // 만약에 전날 익은 총 토마토 개수랑 오늘 익은 총 토마토 개수가 같다면
    // 그게 끝을 의미하니까 그때 flag를 통해 끝내는걸 생각했다
    // 근데 이러면 시간이 너무 오래걸려서 망햇음
    
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
    return 0;
}
