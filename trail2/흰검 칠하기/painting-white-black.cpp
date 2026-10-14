#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int n;
int x[1000];
char dir[1000];
vector < vector < int > > map (200001, vector<int> (3, 0));

int main() {
    cin >> n;
    int pos = 100000;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> dir[i];
    }

    // Please write your code here.
    // 0 이면 안색칠, 1 흰, 2 검, 3 회색
    // [0] 현재색 [1] 흰색이 칠해진횟수 [2] 검은색이칠해진횟수

    for(int i = 0; i < n; i++){
        int amount = x[i];
        char direction = dir[i];

        if(dir[i] == 'L'){ // 흰색으로 칠하기
            for(int j = 0; j < amount; j++){
                map[pos][1]++;
                if(map[pos][1] >= 2 && map[pos][2] >= 2){ //두번이상씩이면
                    map[pos][0] = 3; //회색
                }
                else{
                    map[pos][0] = 1;
                }
                pos--;
            }
            pos++;
        }
        else{
            for(int j = 0; j < amount; j++){
                map[pos][2]++;
                if(map[pos][1] >= 2 && map[pos][2] >= 2){ //두번이상씩이면
                    map[pos][0] = 3; //회색
                }
                else{
                    map[pos][0] = 2;
                }
                pos++;
            }
            pos--;

        }


    }

   
    int white = 0;
    int black = 0;
    int grey = 0;

    for(int i = 0; i < map.size(); i++){
        
        if(map[i][0] == 1){
            white++;
        }
        else if(map[i][0] == 2){
            black++;
        }
        else if(map[i][0] == 3){
            grey++;
        }
    }
    cout << white << " " << black << " " << grey;
    
    return 0;
}