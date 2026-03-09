#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void recall(vector < long long > &s, vector < bool> & ans, long long temp_sum, int idx){ 
    
    for(; idx < s.size(); idx++){ // 처음부터 탐색할 필요 없다. 시작 인덱스부터 시작 (중복되지 않게 원소들을 뽑기니까)
 
        temp_sum = temp_sum + s[idx]; // 원소를 더하고
        ans[temp_sum] = true; // 모든 부분수열의 합을 ans 벡터에 저장해둔다

        recall(s, ans, temp_sum, idx + 1); // 재귀함수로 들어간다. idx + 1 잊지말기

        temp_sum = temp_sum - s[idx]; // 나오면 복구
        
    }
    return;
    
}
int main(){
    int N;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector < long long > S;
    cin >> N;
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        S.push_back(temp);
    }
    // 입력받기
    /*
    시간초과가 떴다. 매 i 루프마다 재귀함수를 통해 모든 합을 구해서 그렇다.

    그렇다면 모든 부분수열의 경우의 수의 합을 한번만 구해 배열로 저장하면 되지 않을까?

    for(int i = 1; ; i++){
        long long sum = 0; // 매 loop 마다 sum은 0이어야하니까
        bool end_flag = false; // 매 loop마다 플래그 초기화

        recall(S, i, end_flag, sum, 0); // 재귀 넣기

        if(end_flag == false){ // 플래그가 false 인 경우는 target 하는 합이 안에서 나오지 않았을때다
            cout << i;
            break;
        }
    }

    */

    vector<bool> ans (2000001, false); // 부분수열의 합을 저장할 배열, 최악의 경우 10만이 20개니까 200만
    long long sum = 0;
    recall(S, ans, sum, 0);
    
    
    for(int i = 1; i < ans.size(); i++){
        if(ans[i] == false){
            cout << i;
            break;
        }
    }
        

}