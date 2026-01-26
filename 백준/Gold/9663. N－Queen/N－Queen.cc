#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

vector < vector<int> > map(15, vector<int> (15, 0));
int ans = 0;
int N;

int temp_cnt;
/* 
struct Position{
    int x;
    int y;
}; 

Position pos; 
*/

void markmap(int m_posx, int m_posy){
    
    for(int i = 0; i < N; i++){ //가로 세로 +2씩 마킹
        // 왜냐하면 한 점이 여러개의 퀸에 의해 불가능할 경우
        // 한 번의 demark로 가능 처리가 돼버릴수 있기 때문에
        map[m_posx][i] += 2;
        map[i][m_posy] += 2;
    }
    int diff = abs(m_posx - m_posy); // 대각선 마킹을 위한 두개의 차
    
    
    // \모양 대각선 처리
    if(m_posx <= m_posy){ 
        for(int i = 0; i + diff < N; i++){
            map[i][i + diff] += 2;
        }
    }
    else{ // (m_posx > m_posy)
        for(int i = 0; i + diff < N; i++){
            map[i + diff][i] += 2;
        }
    }
    
    // /모양 대각선 처리
    int sum = m_posx + m_posy;
    
    if(sum < N){
        for(int i = 0; sum - i >= 0; i++){
            map[i][sum - i] += 2;
        }
    }
    else{
        for(int i = (sum - N + 1); i < N; i++){
            map[i][sum - i] += 2;
        }
    }
    
    map[m_posx][m_posy] = 1;
}

void demarkmap(int m_posx, int m_posy){
        for(int i = 0; i < N; i++){ //가로 세로 -씩 마킹(가능)
        map[m_posx][i] -= 2;
        map[i][m_posy] -= 2;
    }
    int diff = abs(m_posx - m_posy); // 대각선 마킹을 위한 두개의 차
    
    
    // \모양 대각선 처리
    if(m_posx <= m_posy){ 
        for(int i = 0; i + diff < N; i++){
            map[i][i + diff] -= 2;
        }
    }
    else{ // (m_posx > m_posy)
        for(int i = 0; i + diff < N; i++){
            map[i + diff][i] -= 2;
        }
    }
    
    // /모양 대각선 처리
    int sum = m_posx + m_posy;
    
    if(sum < N){
        for(int i = 0; sum - i >= 0; i++){
            map[i][sum - i] -= 2;
        }
    }
    else{
        for(int i = (sum - N + 1); i < N; i++){
            map[i][sum - i] -= 2;
        }
    }
    
    map[m_posx][m_posy] = 0;
}

void func(int t_posx, int t_posy){
    if(t_posx == N){ // 외우자 재귀함수는 탈출조건부터
        // for문을 돌다가 다음 마지막이되면 카운트
        temp_cnt = 0;
        for(int x = 0; x < N; x++){
            for(int y = 0; y < N; y++){
                if(map[x][y] == 1){
                    temp_cnt++;
                }
                
            }
        }
        if(temp_cnt == N){
            ans++;
        }
        return;
    }
    

    
   
    for(int y = 0; y < N; y++){ // for문을 통한 재귀
        // 근데 같은 x축에 마킹이 되면 바로 다음 x축을 보면 되므로 y 만 for문을 돌리면 된다.
        if(map[t_posx][y] == 0){ // 현재 위치가 가능하면
            markmap(t_posx, y); // 맵에 마킹하고
                
            func(t_posx + 1, 0); // 다음 x축을 돌고
                
            demarkmap(t_posx, y); //demark 한다. 그리고 이후에 자동으로 다음 y좌표 탐색
            
            // 이부분이 제일 헷갈렷다. 재귀를 통해 관리하는 x축과
            // 함수 내부의 y축 for 문을 분리하는 논리적 흐름이 어려웟음.
        }
    }

   /* 
    if(map[t_posx][t_posy] == 0){ //빈공간이면 마킹 -> 재귀 -> 디마킹하기
        markmap(t_posx, t_posy);
        
        if(t_posy == N - 1){
            func(t_posx + 1, 0);
        }
        else{
            func(t_posx, t_posy + 1);
        }
        
        demarkmap(t_posx, t_posy);
        
    }
    else{
        
        if(t_posy == N - 1){
            func(t_posx + 1, 0);
        }
        else{
            func(t_posx, t_posy + 1);
        }
    }
    */
    
}

int main(){
    
    cin >> N;
    
    map.resize(N, vector<int>(N, 0));
   
    int posx = 0;
    int posy = 0;
    func(posx, posy);
    cout << ans;
    return 0;
}