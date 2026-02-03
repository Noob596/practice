#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector <int> nn;
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        nn.push_back(temp);
    }
    int M;
    cin >> M;
    sort(nn.begin(), nn.end(), less<int>());
    
    for(int i = 0; i < M; i++){
        int temp;
        cin >> temp;
        if(binary_search(nn.begin(), nn.end(), temp)){
            cout << 1 << "\n";
        }
        else{
            cout << 0 << "\n";
        }
    }
}