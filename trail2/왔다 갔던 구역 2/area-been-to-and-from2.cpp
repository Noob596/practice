#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int x[100];
char dir[100];

vector < int > map (2001, 0);

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> dir[i];
    }
    int pos = 1000;


    for(int i = 0; i < n; i++){
        int movement = x[i];
        int cur_dir = dir[i];

        if(cur_dir == 'R'){
            for(int j = 0; j < movement; j++){
                map[pos]++;
                pos++;
            }
           
        }
        else{
            for(int j = 0; j < movement; j++){
                
                pos--;
                map[pos]++;
            }
            
        }
    }

    sort(map.begin(), map.end(), greater<int>());
    int ans = 0;
    for(int i = 0; map[i] >= 2; i++){
        ans++;
    }
    cout << ans;
    // Please write your code here.

    return 0;
}