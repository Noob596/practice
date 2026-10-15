#include <iostream>
#include <vector>

using namespace std;

int N;
int x1[10], y1[10];
int x2[10], y2[10];
vector <vector < int >> map (200, vector < int > (200, 0));
int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    }
   
    // Please write your code here.
    for(int i = 0; i < N; i++){
        int temp_x1 = x1[i] + 100;
        int temp_y1 = y1[i] + 100;
        int temp_x2 = x2[i] + 100;
        int temp_y2 = y2[i] + 100;
        
        for(int j = temp_x1; j < temp_x2; j++){
            for(int k = temp_y1; k < temp_y2; k++){
                map[j][k] = 1;

            }
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