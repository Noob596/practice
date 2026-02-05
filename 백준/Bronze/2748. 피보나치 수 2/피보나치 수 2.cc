#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector < long long > fb(n + 1);
    fb[0] = 0;
    fb[1] = 1;
    for(int i = 2; i <= n; i++){
        fb[i] = fb[i - 1] + fb[i - 2];
    }

    cout << fb[n];
}