#include <iostream>

using namespace std;

int x1[2], y1[2];
int x2[2], y2[2];
bool map[2001][2001] = {{0, }};

int main() {
    cin >> x1[0] >> y1[0] >> x2[0] >> y2[0];
    cin >> x1[1] >> y1[1] >> x2[1] >> y2[1];
   
    // Please write your code here.
    for(int i = 0; i < 2; i++){
        x1[i] += 1000;
        x2[i] += 1000;
        y1[i] += 1000;
        y2[i] += 1000;
    }

    for(int i = x1[0]; i < x2[0]; i++){
        for(int j = y1[0]; j < y2[0]; j++){
            map[i][j] = 1;
        }
    }

    for(int i = x1[1]; i < x2[1]; i++){
        for(int j = y1[1]; j < y2[1]; j++){
            map[i][j] = 0;
        }
    }
    int minX = 2001;
    int minY = 2001;
    int maxX = -1;
    int maxY = -1;
    for(int i = 0 ; i < 2001; i++){
        for(int j = 0; j < 2001; j++){
            if(map[i][j] == 1){
                if(i < minX){
                    minX = i;
                }
                if(i > maxX){
                    maxX = i;
                }

                if(j < minY){
                    minY= j;
                }
                if (j > maxY){
                    maxY = j;
                }
            }
        }

        
    }
    if(maxX == -1){
        cout << 0;
        return 0;
    }
    int ans = (maxX - minX + 1) * (maxY - minY + 1);
    
    cout << ans;
    return 0;
}