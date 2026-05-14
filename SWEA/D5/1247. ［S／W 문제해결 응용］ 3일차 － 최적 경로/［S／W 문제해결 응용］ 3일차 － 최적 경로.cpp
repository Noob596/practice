#include <iostream>
#include <vector>
#include <cmath>

#define INF 1e9
using namespace std;

int distance(pair<int, int> posone, pair < int, int > postwo){
    return (abs(posone.first - postwo.first) + abs(posone.second - postwo.second)); // 단순거리계산
}

void dfs(pair < int, int>& pos_company, pair<int, int >& pos_home, pair<int, int > cur_pos, vector < bool >& visited, int& answer, vector < pair < int, int > >& position, int& temp_dist){
    if(temp_dist > answer){ // 시간초과떠서 중간에 이거 아니다 싶으면 뒤로간다.
        return;
    }

    int i;
    for(i = 2 ; i < position.size(); i++){
        if(visited[i] == false){ // 안간곳이면
            visited[i] = true; // 방문표시하고
            temp_dist += distance(cur_pos, position[i]); // 거리 Update
            dfs(pos_company, pos_home, position[i], visited, answer, position, temp_dist); // 다음깊이넣고
            visited[i] = false; // 조건복구
            temp_dist -= distance(cur_pos, position[i]);
        }
    } // 이 루프가 다 돌면, 모든 고객사를 돈 거니까 이제 집에 간다.

    // 루프가 다 돌았는지 확인할 때 i를 사용했는데, 그러면 안된다.
    // 중간에 dfs에서 나오는 중간에도 for loop가 끝까지 갈 수 있기 때문에 
    // 모든 고객사를 돌았는지 확인이 필요하다.........

    bool temp_flag = false; // 그래서 플래그를 하나 만들고
    for(int i = 2; i < position.size(); i++){ // 밖 loop에서 한번 확인해준다
        if(visited[i] == false){
            temp_flag = true;
            break;
        }
    }

    if(temp_flag == false){ // 모든 고객사를 돈 것이 확실하면
        temp_dist += distance(pos_home, cur_pos); 
        if(temp_dist < answer){
            answer = temp_dist;
        }
        temp_dist -= distance(pos_home, cur_pos);
    }
}

int main(){
    int t_case;
    cin >> t_case;
    for(int t_c = 1; t_c <= t_case; t_c++){
        vector < pair < int, int > > position (0);
        int pos_cnt;
        cin >> pos_cnt;
        for(int i = 0; i < pos_cnt + 2; i++){
            int tempx, tempy;
            cin >> tempx >> tempy;
            position.push_back({tempx, tempy});
        }
        // [0] 회사 좌표, [1] 집 좌표, 다음 고객 좌표
        vector < bool > visitied (position.size(), false);
        int answer = INF; 
        int temp_dist = 0;
        dfs(position[0], position[1], position[0], visitied, answer, position, temp_dist); // 회사 좌표는 안넣어도 됐을듯
        
        cout << "#" << t_c << " " << answer << "\n";

    }
}