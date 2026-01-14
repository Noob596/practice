#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main(){
    int N;
    cin >> N;
    stack<int> s;
    vector<char> answer;
    int target = 0;
    int cnt = 1;
    s.push(cnt);
    cnt++;
    answer.push_back('+');
    
    int flag = 0;
    
    for(int i = 1; i <= N; i++){
        cin >> target;
        
        while(s.empty() || target > s.top()){
            s.push(cnt);
            cnt++;
            answer.push_back('+');
        }
        
        if(target < s.top()){
            cout << "NO";
            flag = 1;
            break;
        }
        
        if(target == s.top()){
            s.pop();
            answer.push_back('-');
            continue;
        }
        
        
    }
    
    if(flag != 1){
        for(int i = 0; i < answer.size(); i++){
            cout << answer[i] << "\n";
        }
    }
}