#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str;

int main() {
    cin >> str;

    stack <int> s;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '('){
            s.push(1);
        }
        else if(str[i] == ')'){
            if(s.empty()){
                cout << "No";
                return 0;
            }
            else{
                s.pop();
            }
        }


    }
    if(s.empty()){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    // Please write your code here.

    return 0;
}
