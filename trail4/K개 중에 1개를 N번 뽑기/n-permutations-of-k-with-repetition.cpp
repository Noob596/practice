#include <iostream>
#include <vector>

using namespace std;

int K, N;
vector <int > answer;
void choose(int cnt) {          
    if (cnt == N) {             
        for (int i = 0; i < answer.size(); i++)
            cout << answer[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= K; i++) {
        answer.push_back(i);
        choose(cnt + 1);
        answer.pop_back();
    }
}


int main() {
    cin >> K >> N;
    
    // Please write your code here.
    choose(0);
    return 0;
}
