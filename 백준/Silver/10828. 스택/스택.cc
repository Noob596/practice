#include <iostream>
#include <stack> // 스택을 쓰기 위함
#include <string>


using namespace std;

int main(){
    int N;
    cin >> N;
    string command;
    stack <int> s;
    
    for(int i = 0; i < N; i++){
        cin >> command;
        int temp = 0;
        if(command == "push"){ // 코드 짜다가 든 생각 : switch 문을 써도 될 것 같다.
            cin >> temp;
            s.push(temp); // 기초 stack 문법. 맨 위에 push 하기
            continue;
        }
        else if(command == "pop"){
            if(s.empty()){ // 비엇다면 스택.empty() == 1이다
                cout << -1 << "\n";
                continue;
            }
            else{
                temp = s.top(); // stack의 맨 윗 요소 -> .top
                cout << temp << "\n";
                s.pop(); // top을 사용했다면 pop으로 없애주기
                continue;
            }
           
        }
        else if(command == "size"){ // stack의 size 함수
            temp = s.size();
            cout << temp << "\n";
            continue;
        }
        else if(command == "empty"){
            if(s.empty()){
                cout << 1 << "\n"; // empty 함수
            }
            else{
                cout << 0 << "\n";
            }
        }
        else if(command == "top"){
            if(s.empty()){
                cout << -1 << "\n";
            }
            else{
                temp = s.top(); // top은 stack의 제일 위를 pop(없애지) 않는다.
                cout << temp << "\n";
                continue;
            }
        }
    }
    return 0;
}