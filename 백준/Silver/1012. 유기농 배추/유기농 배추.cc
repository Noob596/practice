#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int T;
    cin >> T;

    for(int t_case = 0; t_case < T; t_case++){
        int M, N, K; // 가로 세로 배추개수
        cin >> M >> N >> K;
        vector < vector < int > > map (M, vector < int > (N, 0));
        for(int i = 0; i < K; i++){ // map 입력
            int temp1, temp2;
            cin >> temp1 >> temp2;
            map[temp1][temp2] = -1; // 첫 위치를 -1로 하기
        }
        queue < pair <int, int> > position;
        int group_no = 1;
        int dy[4] = {1, -1, 0, 0};
        int dx[4] = {0, 0, 1, -1};

        for(int x = 0; x < M; x++){ // 돌다가 만나면
            for(int y = 0; y < N; y++){
                if(map[x][y] == -1){ // 여기서 부터 bfs
                    position.push({x, y});
                    while(!position.empty()){
                        int tempx, tempy;
                        tempx = position.front().first;
                        tempy = position.front().second;
                        position.pop();
                        for(int dxy = 0; dxy < 4; dxy++){
                            if(tempx + dx[dxy] < 0 || tempy + dy[dxy] < 0 || tempx + dx[dxy] >= M || tempy + dy[dxy] >= N){
                                continue;
                            }

                            if(map[tempx + dx[dxy]][tempy + dy[dxy]] == -1){
                                map[tempx + dx[dxy]][tempy + dy[dxy]] = group_no;
                                position.push({tempx + dx[dxy], tempy + dy[dxy]});
                            }


                        }
                    }
                    group_no++;
                }
            }
        }

        cout << group_no - 1 << "\n";
    }


}