#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    //시간 -> 분
    for(int i = 0; i < schedules.size(); i++){
        schedules[i] = (schedules[i] / 100 * 60) + schedules[i] % 100;
        for(int j = 0; j < timelogs[i].size(); j++){
            timelogs[i][j] = (timelogs[i][j] / 100 * 60) + timelogs[i][j] % 100;
        }
    }
    //시작을 월요일로 배열 재졍렬
    vector<int> flag(schedules.size(), 0);
    for(int j = 0; j < schedules.size(); j++){
        for(int i = 0; i < startday - 1 ; i++){
            timelogs[j].insert(timelogs[j].begin(), timelogs[j][6]);
            timelogs[j].erase(timelogs[j].end() - 1);
        }
    }
    
    for(int i = 0;i < timelogs.size(); i++){
        for(int j = 0; j < timelogs[i].size(); j++){
            printf("%d ", timelogs[i][j]);
        }
        printf("\n");
    }
    /* 1 이면 담겨잇는 토요일은 5 조작불필요
    2 이면 담겨잇는 토요일은 4 
    3 이면 담겨있는 토요일은 3 
    4 이면 담겨있는 토요일은 2
    5 이면 담겨있는 토요일은 1
    6 이면 담겨있는 토요일은 0
    7 이면 담겨있은 토요일은 6 */
    
    for(int i = 0; i < schedules.size(); i++){ //직원 한명마다
        for(int j = 0; j < 5; j++){
            if(timelogs[i][j] > schedules[i] + 10){
                flag[i] = 1;
            }
        }
    }
    //정답세기
    for(int i = 0; i < flag.size(); i++){
        if(flag[i] == 0){
            answer++;
        }
    }
    return answer;
}