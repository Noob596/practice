#include <iostream>
#include <queue>
#include <string>


using namespace std;

int main(){
    int N;
    cin >> N;
    string command;
    queue <int> q;
    
    for(int i = 0; i < N; i++){
        cin >> command;
        int temp = 0;
        
        if(command == "push"){
            cin >> temp;
            q.push(temp);
            continue;
        }
        else if(command == "pop"){
            if(q.empty()){
                cout << -1 << "\n";
                continue;
            }
            else{
                temp = q.front();
                cout << temp << "\n";
                q.pop();
                continue;
            }
        }
        else if(command == "size"){
            temp = q.size();
            cout << temp << "\n";
            continue;
        }
        else if(command == "empty"){
            if(q.empty()){
                cout << 1 << "\n";
                continue;
            }
            else{
                cout << 0 << "\n";
                continue;
            }
        }
        else if(command == "front"){
            if(q.empty()){
                cout << -1 << "\n";
                continue;
            }
            else{
                temp = q.front();
                cout << temp << "\n";
                continue;
            }
        }
        else if(command == "back"){
            if(q.empty()){
                cout << -1 << "\n";
                continue;
            }
            else{
                temp = q.back();
                cout << temp << "\n";
                continue;
            }
        }
    }
}