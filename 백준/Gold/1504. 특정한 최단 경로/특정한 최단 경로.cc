#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 1e9

using namespace std;

void dijkstra(int start, int target, vector < vector < pair <int, int > > >& map, vector < long long >& distance){
    priority_queue < pair < int, int >, vector < pair < int, int > >, greater < pair < int, int > > > pq;
    distance[start] = 0; // 초기화 잊지 말자..
    pq.push({0, start});

    while(!pq.empty()){
        int curr_dist = pq.top().first;
        int curr_pos = pq.top().second;
        pq.pop();

        if(distance[curr_pos] < curr_dist){
            continue;
        }
        for(int i = 0; i < map[curr_pos].size(); i++){
            int next_dist = map[curr_pos][i].second;
            int next_pos = map[curr_pos][i].first;

            if(distance[next_pos] > curr_dist + next_dist){
                distance[next_pos] = curr_dist + next_dist;
                pq.push({distance[next_pos], next_pos});
            }

        }
    }

}

int main(){
    int N, E;
    cin >> N >> E;

    vector < vector < pair <int, int > > > map (N + 1, vector < pair < int, int > > (0)); // 0번 인덱스는 사용하지 않고,
    // 연결된 도시를 pair로 넣을거다.

    for(int i = 0; i < E; i++){
        int temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;
        map[temp1].push_back({temp2, temp3}); // 연결된 도시 번호, 비용
        map[temp2].push_back({temp1, temp3}); // 양방향 연결이다
    }

    int v1, v2;
    cin >> v1 >> v2;
    /*
    전략: 1번에서 v1 -> v2 ->  N번 정점으로 가는것
    1번에서 v2 -> v1 -> N 번 정점으로 가는것

    둘중에 비용이 더 작은걸 답으로 하면 될 것 같다.

    양방향 연결이고 한번 이동했던 간선도 다시 이동할 수 있으므로

    v1 -> v2 = v2 -> v1 일 거다.

    만약에 시간초과가 뜬다면 v1 -> v2를 한번만 계산하면 되지 않을까? 일단 해보자

    함수를 만들어 쓰는게 더 좋을 것 같다.

    */

    vector < long long > distance_start_v1 (N+1, INF);
    vector < long long > distance_start_v2 (N+1, INF);
    vector < long long > distance_v1_v2 (N+1, INF);
    vector < long long > distance_v1_end (N+1, INF);
    vector < long long > distance_v2_end (N+1, INF);
    dijkstra(1, v1, map, distance_start_v1); // 1 ~ v1
    dijkstra(v1, v2, map, distance_v1_v2); // v1 ~ v2
    dijkstra(v2, N, map, distance_v2_end); // v2 ~ end
    dijkstra(v1, N, map, distance_v1_end); // v1 ~ end
    dijkstra(1, v2, map, distance_start_v2); // 1~v2

    long long ans1 = distance_start_v1[v1] + distance_v1_v2[v2] + distance_v2_end[N];
    long long ans2 = distance_start_v2[v2] + distance_v1_v2[v2] + distance_v1_end[N];
    long long final_ans = min(ans1, ans2);
    if(final_ans >= INF){
        cout << -1;
    }
    else{
        cout << final_ans;
    }

}