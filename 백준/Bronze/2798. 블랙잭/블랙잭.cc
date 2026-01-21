#include <iostream>
#include <vector>

using namespace std;

int N, M;
int temp_sum;
int closest = -1;
int flag = 0;
vector<int> cards;
vector<int> selected;
vector<int> temp; // 카드를 뽑아가는 임시 벡터

void func(){
    if(temp.size() == 3){
        temp_sum = 0;
        for(int j = 0; j < 3; j++){
            temp_sum += temp[j];
        }
        
        if((temp_sum < M) && (temp_sum > closest)){
            closest = temp_sum;
        }
        if(M == temp_sum){
            flag = 1;
        }
        return;
    }
    
    for(int i = 0; i < N; i++){ // N개중에 중복되지 않은걸 하나 뽑을거다. (아까했던 문제)
        if(selected[i] == 0){
            temp.push_back(cards[i]);
            selected[i] = 1;
            func();
            temp.pop_back();
            selected[i] = 0;
        }
    }
    
}
int main(){
    cin >> N >> M;
    int input_temp;
    for(int i = 0; i < N; i++){
        cin >> input_temp;
        cards.push_back(input_temp); // 카드가 N개 있어요~
        selected.push_back(0); // 중복되지 않게 뽑기 위한 벡터
    }
    
    func();
    
    if(flag == 1){
        cout << M;
    }
    else{
        cout << closest;
    }
    
}