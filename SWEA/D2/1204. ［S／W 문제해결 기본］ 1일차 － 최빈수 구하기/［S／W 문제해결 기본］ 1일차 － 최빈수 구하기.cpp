#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int t_case;
        cin >> t_case;
        vector < int > scores (101, 0); // 0점에서 100점까지 101칸의 배열을 만들고
        for(int j = 1; j <= 1000; j++){
            int temp;
            cin >> temp;
            scores[temp]++; // 점수의 횟수를 +1 한다.
        }
        // int max_idx = max_element(scores.begin(), scores.end()) - scores.begin(); // max_element의 반환값은 포인터다. 이렇게 하면 최빈값이 같은 경우 문제가 발생한다.
        int temp = 0; // 반복 횟수의 최대값을 저장하는 임시변수
        int ans;
        for(int j = 0; j < scores.size(); j++){
            if(temp <= scores[j]){ // 최빈값이 같은 경우 더 큰수를 넣기 위해 등호를 넣음
                ans = j;
                temp = scores[j];
            }
        }
        
        cout << "#" << t_case << " " << ans << "\n"; 
    }
}