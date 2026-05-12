#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    
    for(int t_case = 0; t_case < 10; t_case++){
        int cur_t;
        int route; // 간선의 개수
        cin >> cur_t >> route;
        vector < vector < int > > map (100, vector < int > (0)); // 0~99번 도시에 대해 벡터를 만들고, 2차원 벡터로 연결된 지점을 저장
        for(int i = 0; i < route; i++){ // 어디에 뭐가 연결돼있는지 입력받고나서
            int src;
            int dst;
            cin >> src >> dst;
            map[src].push_back(dst);
        }
        queue < int > q; // 큐를 만들어서

        for(int i = 0; i < map[0].size(); i++){ // 처음에 큐에 넣고
            q.push(map[0][i]); // 0번 도시부터 시작
        }
        bool end_flag = false; // 도착 여부를 확인할 플래그 변수
        while(!q.empty()){ // 큐가 빌 때 까지
            int cur_pos = q.front(); // 현재 포지션을 큐에서 빼고
            q.pop();
            if(cur_pos == 99){ // 99번 도시에 도착하면 멈추고
                end_flag = true;
                break;
            }
            for(int i = 0; i < map[cur_pos].size(); i++){ // 연결된 지점을 계속 집어넣는다. BFS
                q.push(map[cur_pos][i]);
            }
        }

        cout << "#" << cur_t; // 출력하기
        if(end_flag){
            cout << " 1\n";
        }
        else{
            cout << " 0\n";
        }

    }
}