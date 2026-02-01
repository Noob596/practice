#include <iostream>
#include <vector>


// dfs 써봐야지 ㅎ히
using namespace std;



void dfs(int position, vector < vector <int> >& network, vector < bool >& infected, int& answer){
    infected[position] = true; // 감염 여부를 확인(방문)하는 벡터에 방문표시
    int next_position;
    answer++; // 감염 +1
    for(int i = 0; i < network[position].size(); i++){ // 연결된 리스트 중에
        if(infected[network[position][i]] == false){ // 감염시킬수 있는게 있으면
            next_position = network[position][i]; // 다음위치
            dfs(next_position, network, infected, answer); // 재귀함수로 dfs 돌리기
        }
    }
}

int main(){
    int computer, lines;
    cin >> computer;
    cin >> lines;
    int answer = -1; // 주의할점: 1번 컴퓨터로 인해 감염되는 컴퓨터의 숫자가 답이므로 1번 컴퓨터는 빼야함. 따라서 초기값 -1로 설정
    vector < vector < int > > network(computer + 1, vector < int> (0));
    // 0번 컴퓨터는 없다
    int temp1, temp2;
    for(int i = 0; i < lines; i++){
        cin >> temp1 >> temp2;
        network[temp1].push_back(temp2);
        network[temp2].push_back(temp1);
    }
    
    vector <bool> infected (computer+1, false);
    
    dfs(1, network, infected, answer); // 1번컴퓨터부터
    cout << answer;
    return 0;
}
