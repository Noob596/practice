#include <iostream>
#include <stack>

using namespace std;

int N;
string command[10000];
int value[10000];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> command[i];
        if (command[i] == "push") {
            cin >> value[i];
        }
    }

    // Please write your code here.
    stack < int> s;

    for(int i = 0; i < N; i++){
        string cur_cmd = command[i];
        if(cur_cmd == "push"){
            int cur_val = value[i];
            s.push(cur_val);

        }
        else if (cur_cmd == "pop"){
            cout << s.top() << "\n";
            s.pop();
        }
        else if (cur_cmd == "size"){
            cout << s.size() << "\n";
        }
        else if(cur_cmd == "empty"){
            cout << s.empty() << "\n";
        }
        else if(cur_cmd == "top"){
            cout << s.top() << "\n";
        }

    }


    return 0;
}
