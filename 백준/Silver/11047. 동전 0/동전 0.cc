#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N;
    long long K;
    cin >> N >> K;
    int cnt = 0;
    /*
    for(int i = 0; i < N; i++){
        long temp;
        cin >> temp;
        coins.push_back(temp);
    }

    for(int i = coins.size() - 1; i >= 0; i--){
        while(coins[i] <= K){
            K = K - coins[i];
            cnt++;
        }

        if(K == 0){
            break;
        }
    }
    */

    // priority queue를 써보자.

    // 동전은 항상 다른것의 배수이므로, 큰 것만 먼저 뽑는(greedy) 가 답이 된다.

    priority_queue<long> coins;
    for(int i = 0; i < N; i++){
        long temp;
        cin >> temp;
        coins.push(temp); // 코인 종류들을 넣고
    }

    while(K != 0){
        if(coins.top() <= K){
            K = K - coins.top(); // 가능한 큰 동전부터 뺀다.
            cnt++;
        }

        else if(coins.top() > K){
            coins.pop();
        }
    }

    cout << cnt;
}
