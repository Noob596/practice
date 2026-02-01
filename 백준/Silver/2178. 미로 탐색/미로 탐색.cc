#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    int temp;
    vector < string > graph (N);  // 0100.. 이 띄어쓰기 없이 주어지므로 스트링으로 만들기
    for(int i = 0; i < N; i++){ // N번 받아서
        cin >> graph[i];
    }
    
    queue < pair <int, int> > q; // x, y 페어로 큐를 만들기(좌표)
    vector < vector < int> > graph_ans(N, vector<int> (M, 0)); // 마지막 끝에 도달 거리를 저장하게 될 map(그래프)
    
    pair <int, int> position = {0, 0}; // 좌표를 페어로
    int dx[4] = {-1, 1, 0, 0}; // 상 하 좌 우
    int dy[4] = {0, 0, -1, 1};
    
    q.push(position); // 처음 bfs를 돌릴 큐에 push 하고
    graph_ans[0][0] = 1; // 0 0 에서 시작하므로 1부터 시작하기
    while(!q.empty()){
        position = q.front(); // 큐에서 빼서
        q.pop();
        // cout << position.first << " " << position.second << endl;
        //탐색
        for(int i = 0; i < 4; i++){ // 상하좌우 탐색을 돌리고
            int nx = position.first + dx[i];
            int ny = position.second + dy[i];

            if(nx >= N || nx < 0 || ny >= M || ny < 0){ // 경계조건이면 continue 하고
                continue;
            }

            if(graph[nx][ny] == '1'){ // 갈 수 있는 길이면 
                q.push({nx, ny}); // 큐에다가 넣고
                graph[nx][ny] = '2'; // '2'로 방문표시를 한다.
                graph_ans[nx][ny] = graph_ans[position.first][position.second] + 1; // 정답 맵에 거리 +1 을 해서 저장하기
            }


        }

    }
    cout << graph_ans[N - 1][M - 1]; // 마지막 출구 좌표값 출력 (= 시작점부터 출력좌표까지 bfs를 몇번 돌았냐? = 최단거리)
    return 0;
}
