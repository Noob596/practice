#include <iostream>
#include <vector>
#include <queue>


#define INF 1e9

using namespace std;



int main(){
    int N, M;

    cin >> N;
    cin >> M;

    vector < vector < pair < int, int > > > map (N + 1, vector < pair < int, int> > (0));
    for(int i = 0; i < M; i++){
        int temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;

        map[temp1].push_back({temp2, temp3}); // 연결된 도시, 비용
    }
    int start, end;
    cin >> start >> end;

    vector < int > distance (N+1, INF);

    priority_queue < pair < int, int > , vector < pair < int, int > > , greater < pair < int, int > > > pq;

    pq.push({0, start}); // 비용, 포지션
    distance[start] = 0;

    while(!pq.empty()){
        int curr_dist = pq.top().first; // 지금 포지션까지 왔던 비용들의 합
        int curr_pos = pq.top().second; // 지금 위치

        pq.pop();

        if(distance[curr_pos] < curr_dist){ // 중복으로 curr_pos 를 왔을 때, 내가 최소값인지 아닌지 판별하는 if문
            // 이 if문에 걸리면 distance[curr_pos]에 이미 최소값이 들어가있다는 뜻이다.
            continue;
        }
        
        for(int i = 0; i < map[curr_pos].size(); i++){
            int next_pos = map[curr_pos][i].first;
            int next_dist = map[curr_pos][i].second;
            
            if(distance[next_pos] > distance[curr_pos] + next_dist){
                distance[next_pos] = distance[curr_pos] + next_dist; // 다음위치의 비용 = 현재까지 비용 + 다음위치까지 가는 비용
                pq.push({distance[next_pos], next_pos}); // 그리고 pq에 넣는다.

            }

        }

    }

    cout << distance[end];

}