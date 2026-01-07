#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    
    vector< vector<int> > spot(N, vector<int>(2, 0));
    
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        spot[i][0] = temp;
        cin >> temp;
        spot[i][1] = temp;
    }
    
    sort(spot.begin(), spot.end());
    
    for(int i = 0; i < N; i ++){
        cout << spot[i][0] << " " << spot[i][1] << "\n";
    }
}