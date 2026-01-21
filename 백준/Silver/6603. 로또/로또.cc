#include <iostream>
#include <vector>

using namespace std;

vector<int> selected;
vector<int> temp;
vector<int> s;
int k;


void func(){
    if(temp.size() == 6){
        for(int j = 0; j < 6; j++){
            cout << temp[j] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i = 0 ;  i < s.size(); i++){
        if((temp.empty()) || (selected[i] == 0) && (temp.back() < s[i])){
            temp.push_back(s[i]);
            selected[i] = 1;
            func();
            temp.pop_back();
            selected[i] = 0;
        }
    }
}

int main(){


    int input_temp;
    while(1){
        cin >> k;
        if(k == 0) break; // 0이면 끝내기
        
        
        for(int i = 0; i < k; i++){
            cin >> input_temp;
            s.push_back(input_temp);
            selected.push_back(0);
        }
        
        func();
        cout << "\n";
        // 벡터들 초기화하기
        
        selected.resize(0);
        temp.resize(0);
        s.resize(0);
    
    }
}