#include <iostream>
#include <vector>

using namespace std;

int main (){
    int T;
    cin >> T;
    /*
    dp[1] = 1
    dp[2] = 2 // 2, 1+1 2가지
    dp[3] 1+1+1, 1+2, (2 1) (3) 4가지
    dp[4] (1 1 1 1 ) (1 1 2) (1 3) (2 2) 7가지
    dp[5] (1 1 1 1 1) 
        (1 1 1 2) <- 여기서 4가지
        (1 1 3) <- 여기서 3가지
        (2 3) <- 2가지
    
    생각해보니 간단함
    맨끝에 +1이 추가되는거, +2가 추가되는거, +3이 추가되는걸 생각해보면됨
    dp[i] = dp[i - 1] + dp[i -2] + dp[i - 3]
        */
    vector<long long> dp (12);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int j = 4; j < 11; j++){
        dp[j] = dp[j -1] + dp[j - 2] + dp[j - 3];
    }
    
    for(int i = 0; i < T; i++){
        int temp;
        cin >> temp;
        cout << dp[temp] << "\n";
    }

}