#include <iostream>
#include <vector>

// 순수 두시간은 고민한거같음 ㅜㅜ

using namespace std;

int N, M;
vector<int> answer; // 수열을 저장할 정답벡터
vector<int> selected; // 1부터 N까지 수가 선택되었는지를 0 1로 표현하는 벡터



void func(){ // 재귀함수로 표현하기 위해 생각을 많이 했다.
    if(answer.size() == M){ // m개를 뽑으면 출력하고 함수 리턴
        //출력
        for(int j = 0; j < answer.size(); j++){
            cout << answer[j] << " ";
        }
        cout << "\n";
        return;
    }
    else{ // m개가 되기 전이면 중복되지 않은 숫자를 하나 더 뽑는다
        for(int i = 1; i <= N; i++){
            if(selected[i - 1] == 0){ // selected 벡터를 돌면서 선택안된 숫자가 있으면
                answer.push_back(i); // 이거를 수열에 넣고
                selected[i - 1] = 1; // selsected 벡터에 이거 썼다고 표시를 하고
                func(); // 재귀함수로 들어감. 사실 직관적으로 와닿지는 않음
                answer.pop_back(); // 상태복원은 여기서 한다 존나중요 이게 존나 헷갈렷다...
                selected[i - 1] = 0; // 사용했던걸 다시 사용안했다고 표현하면 그다음 i 루프를 돌면서 자동으로 다음 숫자로 넘어감.
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        selected.push_back(0); // 맨첨에 N개의 자연수만큼 안썼어요~ 하고 벡터에 넣어주는거임
    }
    
    func();
    return 0;

}