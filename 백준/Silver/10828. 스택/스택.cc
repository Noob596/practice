#include <iostream>
#include <stack>
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
        if(command == "push"){
            cin >> temp;
            s.push(temp);
            continue;
        }
        else if(command == "pop"){
            if(s.empty()){
                cout << -1 << "\n";
                continue;
            }
            else{
                temp = s.top();
                cout << temp << "\n";
                s.pop();
                continue;
            }
           
        }
        else if(command == "size"){
            temp = s.size();
            cout << temp << "\n";
            continue;
        }
        else if(command == "empty"){
            if(s.empty()){
                cout << 1 << "\n";
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
                temp = s.top();
                cout << temp << "\n";
                continue;
            }
        }
    }
}