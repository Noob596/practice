#include <iostream>
#include <vector>


using namespace std;

int n;
int x[1000];
char dir[1000];
vector <int> map(200001, 0);

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> dir[i];
    }
    int pos = 100000;
    // Please write your code here.
    // 회색 0 흰1 검2
    for(int i = 0; i < n; i++){
        int amount = x[i];
        char direction = dir[i];

        if(direction == 'L'){
            for(int j= 0; j < amount; j++){
                map[pos] = 1;
                pos--;
            }
            pos++;
        }
        else{
            for(int j= 0; j < amount; j++){
                map[pos] = 2;
                pos++;
            }
            pos--;
        }
    }
    int white = 0;
    int black = 0;
    for(int i = 0; i < map.size(); i++){
        if(map[i] == 1){
            white++;
        }
        else if(map[i] == 2){
            black++;
        }
    }
    cout << white << " " << black;
    return 0;
}