#include <iostream>
#include <vector>



using namespace std;

int N, M;
vector<int> answer;
vector<int> selected;



void func(){
    if(answer.size() == M){
        //출력
        for(int j = 0; j < answer.size(); j++){
            cout << answer[j] << " ";
        }
        cout << "\n";
        return;
    }
    else{
        for(int i = 1; i <= N; i++){
            if(selected[i - 1] == 0){
                answer.push_back(i);
                selected[i - 1] = 1;
                func();
                answer.pop_back();
                selected[i - 1] = 0;
            }

        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        selected.push_back(0);
    }
    
    func();

}