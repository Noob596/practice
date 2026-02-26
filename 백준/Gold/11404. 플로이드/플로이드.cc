#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e9

using namespace std;

int main(){
    int n, m;
    cin >> n;
    cin >> m;
    /*
    내가 놓친 부분: "시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있다"

    원래는 map 벡터를 만들어 입력을 받고, 이를 cost 벡터에 따로 넣으면서 플로이드 워셜 알고리즘 전에 전처리를 했다.

    근데 함정은 도시를 잇는 노선이 하나가 아닐 수 있어서 틀렸다.

    예제 입력에 잘 보면 1번 도시에서 4번 도시로 가는 노선이, 비용이 1인것과 2인것 두개가 있다. 그래서 틀렸다.

    따라서 바로 입력을 받아서 최소값을 cost 벡터에 넣는 방법을 사용한다.
    */
    vector < vector < int > > cost (n + 1, vector < int > (n + 1, INF)); // 0번 인덱스 사용 안할거고,
    // cost[a][b] 는 a번 도시에서 b번 도시로 가는 비용
    // 무한으로 초기화  
    
    // input 입력
    for(int i = 1; i <= m; i++){
        int temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3; // 출발도시, 도착도시, 비용

        cost[temp1][temp2] = min(cost[temp1][temp2], temp3); // 중복 노선 일 경우 최소값을 cost에 채운다.
    }
    
    for(int i = 1; i < cost.size(); i++){ // 자기 자신으로 가는 비용은 0이다
        cost[i][i] = 0;
    }
    

    // 플로이드 워셜 알고리즘을 써보도록 하자..

    // 거쳐가는 노드, 시작노드, 끝나는 노드 순서다.
    // j 번에서 i를 거쳐 k 로 가는 순서이다.
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                cost[j][k] = min(cost[j][k], cost[j][i] + cost[i][k]);
            }
        }
    }

    for(int i = 1; i <=n; i++){
        for(int j = 1; j<= n; j++){
            if(cost[i][j] == INF){
                cout << "0 ";
            }
            else
                cout << cost[i][j] << " ";
        }
        cout << "\n";
    }

}