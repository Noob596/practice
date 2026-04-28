#include<iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    cin >> test_case;

    for(int t_c = 0; t_c < test_case; t_c++){
        cin>>T;
        vector < pair < int, int > > arr; // x좌표, y좌표
        int max = 0;
        for(int i = 0; i < T; i++){
            int temp1, temp2;
            cin >> temp1 >> temp2;
            arr.push_back({temp1, temp2});
        }
        sort(arr.begin(), arr.end()); // x축으로 오름차순으로 정렬한 뒤

        for(int i = 0; i < arr.size(); i++){
            // 2개씩 선택을 한다.

            int x1 = arr[i].first;
            int y1 = arr[i].second;
            int temp_max = 0;
            for(int j = arr.size() -1 ; j > i; j--){ 
                // x1의 y좌표와 다르면 넘긴다. 즉 x축과 평행한 점이 아니면 넘긴다.
                if(arr[j].second != y1){
                    continue;
                }
                int x2 = arr[j].first;
                int y2 = arr[j].second;

                int delta_x = abs(x1 - x2);
                // y축과 평행한 점이 있는지 찾기
                for(int k = 0; k < arr.size(); k++){
                    if(arr[k].first != x1 && arr[k].first != x2){
                        continue;
                    }
                    int x3 = arr[k].first;
                    int y3 = arr[k].second; // 점을 선택하고
                    if(x3 == x1){ 
                        int temp_size = delta_x * abs(y3 - y1); // 넓이 계산 후
                        if(temp_size > max){ // max값을 Update
                            max = temp_size;
                        }
                    }
                    else{ // x3 == x2
                        int temp_size = delta_x * abs(y3 - y2);
                        if(temp_size > max){
                            max = temp_size;
                        }
                    }

                }
            }
        }
        cout << max << "\n";

        /*
        for(int i = 0; i < arr.size(); i++){
            cout << arr[i].first << " " << arr[i].second << endl;
        }
        */



    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}