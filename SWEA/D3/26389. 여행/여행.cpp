#include <iostream>
#include <vector>

using namespace std;

int main(){
    int test_case;
    cin >> test_case;
    for(int tc = 0; tc < test_case; tc++){
        /*
        집으로 돌아오려면
        한 축으로만 이동하거나
        마지막 두개 move 직전에 어떤 사분면에 존재하는지 판별해야 하나?
        위로 이동하는 move가 있다면 반드시 아래로 move 하는 이동이 있어야 한다고 생각하면
        만약 위로 이동이 2번, 아래 이동이 1번 발생하면 -> 가능
        만약 위로 이동이 2번, 아래 이동이 한번, 마지막에 또 한번의 아래 이동이라면 -> 가능
        그러니 모든 방향이 다 나오거나, 축에서만 이동하면 가능하다.

        */
        string move;
        cin >> move;
        bool N_flag = false; // flag로 생각
        bool S_flag = false;
        bool E_flag = false;
        bool W_flag = false;
        for(int i = 0; i < move.size(); i++){
            char temp = move[i];
            if(move[i] == 'N'){
                N_flag = true;
            }
            else if(move[i] == 'S'){
                S_flag = true;
            }
            else if(move[i] == 'E'){
                E_flag = true;
            }
            else if(move[i] == 'W'){
                W_flag = true;
            }
        }

        if((N_flag && S_flag && E_flag && W_flag) || // 네 방향이 다 나오거나
            (N_flag && S_flag && (!E_flag) && (!W_flag)) || // y축이거나
            ((!N_flag) && (!S_flag) && E_flag && W_flag)){ // x축이면
        
        cout << "Yes" << "\n";
        
        }
        else{
            cout << "No" << "\n";
        }


    }
}