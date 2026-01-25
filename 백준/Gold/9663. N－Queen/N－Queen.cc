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
    
    for(int i = 0; i < N; i++){ //가로 세로 +2씩 마킹(불가능)
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
        for(int i = 0; i < N; i++){ //가로 세로 +2씩 마킹(불가능)
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
    if(t_posx == N){
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
    

    
   
    for(int y = 0; y < N; y++){
        if(map[t_posx][y] == 0){
            markmap(t_posx, y);
                
            func(t_posx + 1, 0);
                
            demarkmap(t_posx, y);
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
}