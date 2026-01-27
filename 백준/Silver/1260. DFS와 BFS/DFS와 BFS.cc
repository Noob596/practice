#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> dfs_route;

void dfs(int position, vector < vector < int > >& graph, vector <bool>& visited){
    dfs_route.push_back(position);
    visited[position] = true;
    int next_position;
    for(int i = 0; i < graph[position].size(); i++){
        if(visited[graph[position][i]] == false){
            next_position = graph[position][i]; // 다음 포지션
            dfs(next_position, graph, visited);
        }
    }
}


int main(){
    int N, M, V;
    cin >> N >> M >> V;
    int temp1, temp2;
    // 머리깨져서 인덱스 0 안쓸거임
    vector < vector <int> > graph(N + 1, vector<int> (0));
    
    for(int i = 0; i < M; i++){
        cin >> temp1 >> temp2;
        graph[temp1].push_back(temp2);
        graph[temp2].push_back(temp1);
    } // 리스트로 넣기
    // sort하기
    for(int i = 1; i <= N; i++){
        if(!graph[i].empty()){
            sort(graph[i].begin(), graph[i].end(), less<int>());
        }
    }
    
    
    //DFS
    int position_dfs = V;
    stack <int> s;
    vector <bool> visited (N + 1, false);
    dfs(position_dfs, graph, visited);

    for(int i = 0; i < dfs_route.size(); i++){
        cout << dfs_route[i] << " ";
    }
    cout << "\n";

    for(int i = 0; i < visited.size(); i++){
        visited[i] = false;
    } 
    // BFS

    int position_bfs = V;
    queue <int> q;
    //vector<bool> visited (N+1, false);
    vector <int> bfs_route;

    q.push(position_bfs);
    visited[position_bfs] = true;

    while(!q.empty()){

        position_bfs = q.front();
        bfs_route.push_back(position_bfs);
        q.pop();

        for(int i = 0; i < graph[position_bfs].size(); i++){
            if(visited[graph[position_bfs][i]] == false){
                q.push(graph[position_bfs][i]);
                visited[graph[position_bfs][i]] = true;
            }
        }
        
    }

    for(int i = 0; i < bfs_route.size(); i++){
        cout << bfs_route[i] << " ";
    }
}