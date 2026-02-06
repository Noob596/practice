#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main(){
    long N;
    cin >> N;
    // long long num =1;
    // long cnt = 0;
    vector < int > dp(N + 1); // 잘안와닿는다...
    
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for(int i = 4; i <= N; i++){
        int switchh = 0;

        if(i % 6 == 0){
            switchh = 3;
        }
        else{
            if(i % 3 == 0){
                switchh = 2;
            }
            else if(i % 2 == 0){
                switchh = 1;
            }
            else{
                switchh = 0;
            }
        }

        switch(switchh){
            case 0:
                dp[i] = dp[i - 1] + 1;
                break;
            case 1:
                dp[i] = min({dp[i / 2], dp[i - 1]}) + 1;
                break;
            case 2:
                dp[i] = min({dp[i / 3], dp[i - 1]}) + 1;
                break;
            case 3:
                dp[i] = min({dp[i / 3], dp[i / 2], dp[i - 1]}) + 1;
                break;
        }
    
        
    }
    cout << dp[N];
    /*
    dp[i] -> i를 1로 만드는데 필요한 최소 연산 횟수 라고 하면
    dp[1] = 0
    dp[2] = 1 (한번빼기)
    dp[3] = 1 (3나누기)
    dp[4] = 2 (2나누고 2나누기) -> 1 + dp[2]
    dp[5] = 3 (1 빼고 2 나누기 2나누기
                1 빼고 1 빼고 3 나누기) - >
    dp[6] = 2 (3나누기 2나누기)
    dp[7] = 3 (1빼고 3나누고 2나누기)

    흠..
    */

    
    
}