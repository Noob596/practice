#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    long long K;
    cin >> N >> K;
    vector < long > coins;
    int cnt = 0;
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

    cout << cnt;
}