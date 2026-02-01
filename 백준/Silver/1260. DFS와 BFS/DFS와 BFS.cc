#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> dfs_route; // dfs에서 방문 기록을 저장할 벡터

void dfs(int position, vector < vector < int > >& graph, vector <bool>& visited){ // dfs는 재귀함수로 선언
    dfs_route.push_back(position); // 함수에서 받은 포지션을 정답 벡터에 넣고
    visited[position] = true; // 방문 체크 후에
    int next_position;
    for(int i = 0; i < graph[position].size(); i++){ // graph에 연결돼있는 위치들을 돌면서
        if(visited[graph[position][i]] == false){ // 방문했던 곳이 아니면
            next_position = graph[position][i];
            dfs(next_position, graph, visited); // 다음 포지션에 대해 dfs 재귀 실행
        }
    }
}


int main(){
    int N, M, V;
    cin >> N >> M >> V;
    int temp1, temp2;
    // 머리깨져서 인덱스 0 안쓸거임
    vector < vector <int> > graph(N + 1, vector<int> (0)); // 인덱스 0을 안쓸거라서 N + 1개 2차원 벡터를 만들고
    
    for(int i = 0; i < M; i++){
        cin >> temp1 >> temp2;
        graph[temp1].push_back(temp2);
        graph[temp2].push_back(temp1);
    } // 리스트로 넣기
    // sort하기
    for(int i = 1; i <= N; i++){ // 문제 조건에서 숫자가 작은곳부터 탐색하기 위해 sort
        if(!graph[i].empty()){
            sort(graph[i].begin(), graph[i].end(), less<int>());
        }
    }
    
    
    //DFS
    int position_dfs = V;
    stack <int> s;
    vector <bool> visited (N + 1, false);
    dfs(position_dfs, graph, visited);

    for(int i = 0; i < dfs_route.size(); i++){ //출력
        cout << dfs_route[i] << " ";
    }
    cout << "\n";

    for(int i = 0; i < visited.size(); i++){ //bfs를 위해 방문 저장 벡터 초기화
        visited[i] = false;
    } 
    // BFS

    int position_bfs = V;
    queue <int> q;
    
    vector <int> bfs_route;

    q.push(position_bfs); // 처음 시작 위치를 큐에 넣고
    visited[position_bfs] = true; // 시작 위치 방문 표시 잊지말기

    while(!q.empty()){ // 큐가 빌때까지

        position_bfs = q.front(); // 포지션을 빼고
        bfs_route.push_back(position_bfs); // 정답 벡터에 넣고
        q.pop();

        for(int i = 0; i < graph[position_bfs].size(); i++){ 
            if(visited[graph[position_bfs][i]] == false){ // 이동 할 수 있는 노드를
                q.push(graph[position_bfs][i]); // 전부 큐에 push 하고
                visited[graph[position_bfs][i]] = true; // 방문처리한다.
            }
        }
        // 이거를 큐가 빌때까지 함
        
    }

    for(int i = 0; i < bfs_route.size(); i++){
        cout << bfs_route[i] << " ";
    }
}
