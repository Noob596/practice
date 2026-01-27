#include <iostream>
#include <vector>


// dfs 써봐야지 ㅎ히
using namespace std;



void dfs(int position, vector < vector <int> >& network, vector < bool >& infected, int& answer){
    infected[position] = true;
    int next_position;
    answer++;
    for(int i = 0; i < network[position].size(); i++){
        if(infected[network[position][i]] == false){
            next_position = network[position][i];
            dfs(next_position, network, infected, answer);
        }
    }
}

int main(){
    int computer, lines;
    cin >> computer;
    cin >> lines;
    int answer = -1;
    vector < vector < int > > network(computer + 1, vector < int> (0));
    // 0번 컴퓨터는 없다
    int temp1, temp2;
    for(int i = 0; i < lines; i++){
        cin >> temp1 >> temp2;
        network[temp1].push_back(temp2);
        network[temp2].push_back(temp1);
    }
    
    vector <bool> infected (computer+1, false);
    
    dfs(1, network, infected, answer);
    cout << answer;
}