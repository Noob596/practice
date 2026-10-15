#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int x1[3], y1[3];
int x2[3], y2[3];

vector < vector < int > > map (2001, vector < int > (2001, 0));
int main() {
    cin >> x1[0] >> y1[0] >> x2[0] >> y2[0];
    cin >> x1[1] >> y1[1] >> x2[1] >> y2[1];
    cin >> x1[2] >> y1[2] >> x2[2] >> y2[2];

    // Please write your code here.
    for(int i = 0; i < 3; i++){
        x1[i] += 1000;
        y1[i] += 1000;
        x2[i] += 1000;
        y2[i] += 1000;
    }
    for(int i = x1[0]; i < x2[0]; i++){
        for(int j = y1[0]; j < y2[0]; j++){
            map[i][j] = 1;
        }
    }
    for(int i = x1[1]; i < x2[1]; i++){
        for(int j = y1[1]; j < y2[1]; j++){
            map[i][j] = 1;
        }
    }

    for(int i = x1[2]; i < x2[2]; i++){
        for(int j = y1[2]; j < y2[2]; j++){
            map[i][j] = 0;
        }
    }
    int ans = 0;
    for(int i = 0; i < map.size(); i++){
        for(int j = 0; j < map[i].size(); j++){
            if(map[i][j] == 1){
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}