#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    /*
    카드 비교 횟수를 구하자.

    10, 20, 40 이 있다고 가정하면

    (10 + 20) + (30 + 40) = 100
    (10 + 40) + (50 + 20) = 120

    그러니까 예를 들면 3개의 묶음일 경우

    (A + B) + ((A + B) + C) = 2A + 2B + C 가 최소가 되는 값

    -> 두번 들어가는 a 와 b 가 제일 작은 두개여야 할 것이다.

    4개 묶음의 경우

    (A + B) + ((A + B) + C) + ((A + B + C) + D) = 3A + 3B + 2C + D 또는
    (A + B) + (C + D) + ((A + B) + (C + D)) = 2A + 2B + 2C + 2D 중 최소일 것이다..
    
    A <= B <= C <= D 라고 하면
    
    A + B >= D 인 경우에는 아래가 최소
    반대의 경우 위가 최소일 것이다..
    

    5개 묶음의 경우
    (A + B) + ((A + B) + C) + ((A + B + C) + D) +.. = 4A + 4B + 3C + 2D + E
    (A + B) + (C + D) + ((A + B) + (C + D)) + ((A + B + C + D) + E) = 3A + 3B + 3C + 3D + E
    (A + B) + (C + D) + ((A + B) + E) + ((A + B + E) + (C + D)) = 3A + 3B + 2C + 2D + 2E
    모르겟다 으악

    힌트를 보고 왔다. 항상 극단적으로 생각하기..
    10 10 1000 1000 잇다고 하면
    10 10 합쳐서 20만들고
    1000 20 합치면 1200
    1200 1000 합치면 2200 총 2420

    10 10 합쳐서 20 만들고
    1000 1000 합쳐서 2000 만들고
    20 2000 합쳐서 2020 만들면 
    4040 이다.

    카드 묶음들 중에서 그냥 계속 제일 작은거 두개끼리 합치면 된다.
    나는 문어다..
    */
    int N;
    cin >> N;
    priority_queue<int, vector <int>, greater<int>> cards; // 이건 외웠다.
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        cards.push(temp); // 카드 다 입력받아 넣고
    }
    int ans = 0;
    while(1){
        if(cards.size() == 1){ // 카드 묶음들이 1개가 되면 끝
            break;
        }

        int temp1 = cards.top(); // 제일 작은 카드 묶음 두개를 더한다.
        cards.pop();
        int temp2 = cards.top();
        cards.pop();

        cards.push(temp1+temp2); // 더한 묶음을 카드 뭉치에 다시 넣는다
        ans += (temp1 + temp2); // 앞선 프로세스는 카드 뭉치를 만드는거지, 비교 횟수를 저장하는게 아니니까 ans에 더한다. 이거 실수했다.

    }
    cout << ans;

}
