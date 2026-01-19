#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> q;
    int N, k;
    cin >> N;
    cin >> k;
    int temp;
    vector<int> answer;
    // 문제 접근:
    // 원형 큐로 생각했더니 idx 관리가 힘들것 같았음
    // 그래서 아이디어 : 그냥 큐에 계속 넣고 빼면서(원형큐처럼)
    // k번째 마다 아예 큐에서 빼서 정답 벡터에 push back 하기
    for(int i = 1; i <= N; i++){
        q.push(i);
    } // queue 생성
    
    while(!q.empty()){ // 큐에 남은게 없을때까지
        temp = 0; // temp 값 초기화(프론트값)
        for(int i = 1; i <= k; i++){ // 큐 내부를 돌다가
            if(i == k){ // k번째가 되면
                temp = q.front();
                q.pop(); //큐의 front 를 없애고
                answer.push_back(temp); // 그걸 정답 벡터에 push back
            }
            else{ //k 번째가 아닐땐
                temp = q.front(); //임시 변수 써가지고
                q.pop(); // front 꺼를 없애고
                q.push(temp); // 뒤쪽에다 push
            }
        }
    }
    cout << "<"; // 출력부분
    for(int i = 0; i < answer.size(); i++){
        if(i == answer.size() - 1){
            cout << answer[i] << ">" << "\n";
        }
        else{
            cout << answer[i] << ", ";
        }
    }
    return 0;
}
