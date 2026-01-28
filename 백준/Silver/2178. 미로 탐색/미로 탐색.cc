#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    int temp;
    vector < string > graph (N); 
    for(int i = 0; i < N; i++){
        cin >> graph[i];
    }
    
    queue < pair <int, int> > q;
    vector < vector < int> > graph_ans(N, vector<int> (M, 0));
    bool end_flag = false;
    pair <int, int> position = {0, 0};
    int dx[4] = {-1, 1, 0, 0}; // 상 하 좌 우
    int dy[4] = {0, 0, -1, 1};
    //int answer = 1;
    q.push(position);
    graph_ans[0][0] = 1;
    while(!q.empty()){
        position = q.front();
        q.pop();
        // cout << position.first << " " << position.second << endl;
        //탐색
        for(int i = 0; i < 4; i++){
            int nx = position.first + dx[i];
            int ny = position.second + dy[i];

            if(nx >= N || nx < 0 || ny >= M || ny < 0){
                continue;
            }

            if(graph[nx][ny] == '1'){
                q.push({nx, ny});
                graph[nx][ny] = '2';
                graph_ans[nx][ny] = graph_ans[position.first][position.second] + 1;
            }


        }

    }
    cout << graph_ans[N - 1][M - 1];
}