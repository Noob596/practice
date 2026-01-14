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
    for(int i = 1; i <= N; i++){
        q.push(i);
    } // queue 생성
    
    while(!q.empty()){
        temp = 0;
        for(int i = 1; i <= k; i++){
            if(i == k){
                temp = q.front();
                q.pop();
                answer.push_back(temp);
            }
            else{
                temp = q.front();
                q.pop();
                q.push(temp);
            }
        }
    }
    cout << "<";
    for(int i = 0; i < answer.size(); i++){
        if(i == answer.size() - 1){
            cout << answer[i] << ">";
        }
        else{
            cout << answer[i] << ", ";
        }
    }
}
