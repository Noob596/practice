#include <iostream>
#include <vector>

using namespace std;
void smell_decrease(vector < vector < pair < int, int > > >& smell_map, int N){ // 상어 초를 감소시키기
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(smell_map[i][j].second >= 1){
                smell_map[i][j].second--;
                if(smell_map[i][j].second == 0){
                    smell_map[i][j].first = 0;
                }
            }
        }
    }
}

int main(){
    int N, M, k;
    cin >> N >> M >> k;

    vector < vector < pair < int, int > > > shark_map (N, vector < pair < int, int > > (N, {0, 0})); // 2차원 배열에 pair 로 {상어번호, 방향} 을 저장해보자
    vector < vector < pair < int, int > > > smell_map (N, vector < pair < int, int > > (N, {0, 0})); // 냄새도 2차원 배열에 {상어번호, 남은 턴} 으로 저장해보자

    for (int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int temp;
            cin >> temp;
            if(temp != 0){
                shark_map[i][j].first = temp; // 상어 번호를 넣고
                smell_map[i][j].first = temp; // 냄새 map에 상어번호와
                smell_map[i][j].second = k; // 남은 턴 수를 넣는다.
            }
            
        }
    }

    vector < pair < int , int > > direction = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 1 2 3 4 = 위 아래 왼쪽 오른쪽 순서, x y 순서, 0번 인덱스 사용 안함
    // 이거 조심하자..
    
    vector < int > temp_direction; // 처음 방향을 입력받을 임시벡터
    temp_direction.push_back(0); // 0번 상어는 없다
    for(int i = 0; i < M; i++){
        int temp;
        cin >> temp;
        temp_direction.push_back(temp);
    } // 초기 방향 받고

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(shark_map[i][j].first != 0){
                shark_map[i][j].second = temp_direction[shark_map[i][j].first];
            }
        }
    }
    // 3차원 벡터로 상어들의 우선순위를 저장하자. 우선순위[상어번호][현재방향][0~3 4개의 우선순위]
    // 상어번호, 현재 방향은 인덱스 0을 사용하지 않는다.
    vector < vector < vector < int > > > shark_priority (M + 1, vector < vector < int > > (5, vector < int > (4, 0)));

    for(int i = 1; i <= M ; i++){
        for(int j = 1; j <= 4; j++){
            for(int k = 0; k < 4; k++){
                int temp;
                cin >> temp;
                shark_priority[i][j][k] = temp;
            }
        }
    }

    // 상어의 position을 담을 벡터, 첫번째 이동 이후에는 상어의 포지션을 저장한다.[상어번호]에다 {다음포지션x, 다음포지션y}

    vector < pair < int, int > > shark_position (M + 1, {0, 0}); // 0번 상어는 업다
    vector < int > shark_direction (M + 1, 0); // 방향을 저장해둔다.
    vector < bool > dead_flag (M+1, false); // 쫓겨난 상어를 저장
    

    // 처음에는 각 상어마다 인접한 ''빈칸''이 존재한다
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(shark_map[i][j].first != 0){
                int cur_shark_num = shark_map[i][j].first; // i j 위치의 상어 번호
                int cur_shark_dir = shark_map[i][j].second; // 그 상어가 지금 바라보고 있는 방향
                // 상하좌우 탐색
                
                for(int k = 0; k < 4; k++){
                    int next_dir = shark_priority[cur_shark_num][cur_shark_dir][k]; // 다음 가야할 방향은 우선순위에 따르며
                    int nx = i + direction[next_dir].first; // 다음 x좌표
                    int ny = j + direction[next_dir].second; // 다음 y좌표
                    
                    if(nx < 0 || nx >= N || ny < 0 || ny >= N){ // 한번은 반드시 가능하므로 경계조건만 따진다.
                        continue;
                    }
                    
                    shark_position[cur_shark_num] = {nx, ny}; // 다음 위치에 넣고
                    shark_direction[cur_shark_num] = next_dir;
                    shark_map[i][j].first = 0; // 상어가 있던 위치를 초기화한다.
                    shark_map[i][j].second = 0;
                    break;
                }
            }
        }
    }
    smell_decrease(smell_map, N); // 맵의 모든 냄새들을 -1 하고 새 위치의 냄새를 넣어준다
    // 상어 맵에 한번에 업데이트한다. 이때 두 상어가 같은 위치에 존재하면 쫓아낸다.
    for(int i = 1; i <= M; i++){
        if(dead_flag[i] == true){
            continue;
        }
        if(shark_map[shark_position[i].first][shark_position[i].second].first != 0){
            // 맵을 업데이트하는 과정에서, 그 위치에 다른 상어가 있으면
            int winner_shark;
            
            if(shark_map[shark_position[i].first][shark_position[i].second].first < i){
                winner_shark = shark_map[shark_position[i].first][shark_position[i].second].first;
                dead_flag[i] = true;
            }
            else{
                winner_shark = i;
                dead_flag[shark_map[shark_position[i].first][shark_position[i].second].first] = true;
            }

            shark_map[shark_position[i].first][shark_position[i].second].first = winner_shark;
            shark_map[shark_position[i].first][shark_position[i].second].second = shark_direction[winner_shark];
            smell_map[shark_position[i].first][shark_position[i].second].first = winner_shark;
            smell_map[shark_position[i].first][shark_position[i].second].second = k;
        }
        else{
            shark_map[shark_position[i].first][shark_position[i].second].first = i;
            shark_map[shark_position[i].first][shark_position[i].second].second = shark_direction[i];
            smell_map[shark_position[i].first][shark_position[i].second].first = i;
            smell_map[shark_position[i].first][shark_position[i].second].second = k;
        }
    }

    int ans = 1; // 한번 돌아서 1초 추가.
    // 이제 맵 전체가 아닌 상어 포지션으로 맵을 돈다
    while(ans <= 1000){
        bool finish_flag = true;
        // 상어가 1번만 남았는지 확인
        for(int i = 2; i <= M; i++){
            if(dead_flag[i] == false){
                finish_flag = false;
            }
        }

        if(finish_flag == true){
            break;
        }
        /*
        순서를 잘 생각해보자.

        먼저 상어위치를 토대로 다음에 이동할 좌표를 계산한다.

        이때 우선순위를 생각하면, 아무 냄새가 없는 칸으로 먼저 이동한다. 즉, 탐색 조건에 아무 냄새가 없음 && 맵 경계
        (k = 0; k < 4)
        이 루프를 돌고도 이동을 못하면 (k == 4)
        그 때 내 냄새가 있는 방향으로 이동한다. 왜냐하면

            다른상어냄새
        빈 공간   현재위치   내 냄새
            다른상어냄새
        
        이런 경우에, 우선순위가 상 우 하 좌 순서라고 가정하면 좌로 이동해야하지만 내 냄새가 있던 방향으로 이동하기 때문이다.


        */

        for(int i = 1; i <= M; i++){
            int cur_shark_num = i;
            if(dead_flag[cur_shark_num] == true){
                continue;
            }
            pair < int , int > cur_pos = shark_position[i];
            int cur_shark_dir = shark_map[cur_pos.first][cur_pos.second].second;
            // 이제 상하좌우 탐색

            int j = 0;
            for(j = 0; j < 4; j++){
                int next_dir = shark_priority[cur_shark_num][cur_shark_dir][j];
                int nx = cur_pos.first + direction[next_dir].first;
                int ny = cur_pos.second + direction[next_dir].second;

                if(nx < 0 || nx >= N || ny < 0 || ny >= N || (smell_map[nx][ny].first != 0)){
                    continue;
                }

                shark_position[cur_shark_num] = {nx, ny}; // 다음 위치에 넣고
                shark_direction[cur_shark_num] = next_dir;
                shark_map[cur_pos.first][cur_pos.second].first = 0; // 상어가 있던 위치를 초기화한다.
                shark_map[cur_pos.first][cur_pos.second].second = 0;
                break;

            }
            if(j == 4){ // 만약 인접한 빈 칸이 없다면 우선순위에 따라 내 냄새가 있는 칸으로 이동한다.
                for(int k = 0; k < 4; k++){
                    int next_dir = shark_priority[cur_shark_num][cur_shark_dir][k];
                    int nx = cur_pos.first + direction[next_dir].first;
                    int ny = cur_pos.second + direction[next_dir].second;
                    if(nx < 0 || nx >= N || ny < 0 || ny >= N || (smell_map[nx][ny].first != cur_shark_num)){
                        continue;
                    } 
                    shark_position[cur_shark_num] = {nx, ny}; // 다음 위치에 넣고
                    shark_direction[cur_shark_num] = next_dir;
                    shark_map[cur_pos.first][cur_pos.second].first = 0; // 상어가 있던 위치를 초기화한다.
                    shark_map[cur_pos.first][cur_pos.second].second = 0;
                    break;
                }
            }
        }
        // 냄새를 -1 하고
        smell_decrease(smell_map, N);
        // 맵에 업데이트하기

        for(int i = 1; i <= M; i++){
            if(dead_flag[i] == true){
                continue;
            }

            if(shark_map[shark_position[i].first][shark_position[i].second].first != 0){
                // 맵을 업데이트하는 과정에서, 그 위치에 다른 상어가 있으면
                int winner_shark;

                if(shark_map[shark_position[i].first][shark_position[i].second].first < i){
                    winner_shark = shark_map[shark_position[i].first][shark_position[i].second].first;
                    dead_flag[i] = true;
                }
                else{
                    winner_shark = i;
                    dead_flag[shark_map[shark_position[i].first][shark_position[i].second].first] = true;
                }

                shark_map[shark_position[i].first][shark_position[i].second].first = winner_shark;
                shark_map[shark_position[i].first][shark_position[i].second].second = shark_direction[winner_shark];
                smell_map[shark_position[i].first][shark_position[i].second].first = winner_shark;
                smell_map[shark_position[i].first][shark_position[i].second].second = k;
            }
            else{
                shark_map[shark_position[i].first][shark_position[i].second].first = i;
                shark_map[shark_position[i].first][shark_position[i].second].second = shark_direction[i];
                smell_map[shark_position[i].first][shark_position[i].second].first = i;
                smell_map[shark_position[i].first][shark_position[i].second].second = k;
            }
        }
        //
        
        ans++;
    }
    if(ans == 1001){
        cout << -1;
        return 0;
    }
    cout << ans;
    return 0;

    

    // 첫 이동을 굳이 따로 빼야했을까. 처음에 상어 맵을 받으면서 위치를 받을 걸 그랬다.
    
    
    
    
    /*
    for(int i = 1; i < M + 1; i++){
        cout << i << "번 상어 :" << endl;
        for(int j = 1; j < 5; j++){
            for(int k = 0; k < 4; k++){
                
                cout << shark_priority[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    */
    
    /*
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << smell_map[i][j].first << " ";
        }
        cout << endl;
    }
    
    for(int i = 0; i < shark_position.size(); i++){
        cout << shark_position[i].first << " " << shark_position[i].second << endl;
    }
    */

}