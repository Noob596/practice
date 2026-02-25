#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


#define INF 1e9

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E; // 정점, 간선 개수
    cin >> V >> E;
    int K; // 시작지점
    cin >> K;

    vector < vector < pair < int, int> > > graph (V + 1, vector < pair < int, int > > (0)); // 0번 정점 사용 안함, first는 연결된 정점, second 는 가중치
    graph[0].push_back({NULL, NULL});
    for(int i = 0; i < E; i++){
        int temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;

        graph[temp1].push_back({temp2, temp3});
        //graph[temp2].push_back({temp1, temp3});
        // 실수한 부분. 쌍방 통행이 아니라 일방통행이다.

    }

    priority_queue< pair < int, int >, vector < pair < int , int > >, greater < pair < int , int > > > pq; // 오름차순 정렬
    
    
    vector<int> dist(V+1, INF); // 0번 인덱스 쓰지말자


    pq.push({0, K}); // 거리, 위치
    dist[K] = 0; // K 지점부터 K까지 거리는 0
    while(!pq.empty()){
        int dist_now = pq.top().first;
        int pos_now = pq.top().second;
        
        pq.pop();

        if(dist[pos_now] < dist_now){ // pq에는 비용들을 누적합해서 계속 갖고다닌다.
            // 지금까지 누적된 합이 pos_now 로 가는 것 보다 작다면 그게 최소값이니까 if문에 걸리지 않고
            // 반대라면 dist[pos_now] 에 값이 최소값이므로 continue로 패스한다
            continue;
        }

        for(int i = 0; i < graph[pos_now].size(); i++){ // 그래프를 돌면서 연결돼있는 리스트를 보고
            int next_pos = graph[pos_now][i].first;
            int next_dist = graph[pos_now][i].second;

            if(dist_now + next_dist < dist[next_pos]){ //다음 위치로 가는비용의 총합이, dist배열에 담긴 값보다 작다면
                dist[next_pos] = dist_now + next_dist; // dist[다음위치] 값을 업데이트 해 주고
                pq.push({dist[next_pos], next_pos}); // 큐에 넣는다.
            }

        }
        
        

        
    }
    for(int i = 1; i <= V; i++){
        if(dist[i] == INF){
            cout << "INF\n";
        }
        else
            cout << dist[i] << "\n";
    }
}