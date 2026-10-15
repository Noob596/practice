#include <iostream>
#include <vector>

using namespace std;

int N;
int x[100], y[100];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    // Please write your code here.
    vector < vector < bool > > map (201, vector < bool > (201, 0));

    for(int loop = 0; loop < N; loop++){
        int temp_x = x[loop] + 100;
        int temp_y = y[loop] + 100;

        for(int i = temp_x; i < temp_x + 8; i++){
            for(int j = temp_y; j < temp_y + 8; j++){
                map[i][j] = 1;
            }
        }

    }
    int ans = 0;
    for(int i = 0; i < map.size(); i++){
        for(int j= 0; j < map[i].size(); j++){
            if(map[i][j] == 1){
                ans++;
            }
        }
    }

    cout << ans;
    return 0;
}