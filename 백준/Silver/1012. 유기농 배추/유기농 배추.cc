#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 문제 요약: 덩어리가 몇개 있냐 세는거다

int main(){
    int T;
    cin >> T;

    for(int t_case = 0; t_case < T; t_case++){
        int M, N, K; // 가로 세로 배추개수
        cin >> M >> N >> K;
        vector < vector < int > > map (M, vector < int > (N, 0)); // 모두 0으로 채운 담에
        for(int i = 0; i < K; i++){ // map 입력
            int temp1, temp2;
            cin >> temp1 >> temp2;
            map[temp1][temp2] = -1; // 배추가 있는 위치를 -1로 할꺼다.
        }
        queue < pair <int, int> > position;
        int group_no = 1; // 그래서 시작은 1번 그룹이다
        int dy[4] = {1, -1, 0, 0};
        int dx[4] = {0, 0, 1, -1};

        for(int x = 0; x < M; x++){ // 맵 전체를 돌다가
            for(int y = 0; y < N; y++){
                if(map[x][y] == -1){ // 여기서 배추를 만나면 bfs를 돌린다.
                    position.push({x, y}); // 먼저 포지션을 페어 큐에 넣고
                    map[x][y] = group_no; // 이거 ~번 그룹이에요 표시한다음에
                    while(!position.empty()){ // 큐가 빌때까지 돌려버린다
                        int tempx, tempy;
                        tempx = position.front().first;
                        tempy = position.front().second;
                        position.pop();
                        for(int dxy = 0; dxy < 4; dxy++){
                            if(tempx + dx[dxy] < 0 || tempy + dy[dxy] < 0 || tempx + dx[dxy] >= M || tempy + dy[dxy] >= N){
                                continue;
                            } // 경계조건

                            if(map[tempx + dx[dxy]][tempy + dy[dxy]] == -1){ // 인접한 배추가 있으면
                                map[tempx + dx[dxy]][tempy + dy[dxy]] = group_no; // 같은 그룹이라고 표시한다
                                position.push({tempx + dx[dxy], tempy + dy[dxy]}); // 얘도 큐에 넣는다(bfs)
                            }


                        }
                    }
                    group_no++; // 그룹처리 한번 돌리고 다음그룹 체킹을 위해 그룹넘버 +1해버리기
                }
            }
        }

        cout << group_no - 1 << "\n"; // 마지막 그룹을 표시하고, 다음 그룹을 위해 +1 되어있는 상태이므로 -1을 해주면 정답이당
    }
    
    return 0;


}
