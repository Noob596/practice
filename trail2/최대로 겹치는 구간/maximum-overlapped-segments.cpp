#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int x1[100], x2[100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
        x1[i] +=100;
        x2[i]+= 100;
    }

    vector < int > map(201, 0);

    for(int i = 0; i < n; i++){
        int start = x1[i];
        int end = x2[i];

        for(int j = start; j < end; j++){
            map[j]++;
        }
    }
    sort(map.begin(), map.end(), greater<int>());
    cout << map[0];
    // Please write your code here.

    return 0;
}