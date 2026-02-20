#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int N;
    /*
    회의 진행 시간이 짧은 것을 먼저선택하는게 최대한이지 않을까?
    극단적으로

    1 10
    10 20

    8 11

    이렇게 있다고 생각하면
    회의시간이가장짧은 8 11 선택해버리면
    1개밖에못함

    답은 1 10, 10 20 두개인데

    그러므로 회의시간이 가장 짧은걸 선택하는건 아님..

    

    답은.. 끝나는 시간이 빠른것부터 greedy 하게 선택하는 것이다.
    슬프다..
    
    */

    cin >> N;
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > table;

    for(int i = 0; i < N; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;

        table.push({temp2, temp1}); // 끝나는 시간으로 오름차순을 한다.
    }
    
    int prev_end = 0;
    int ans = 0;
    while(!table.empty()){
        /*cout << table.top().first << " " << table.top().second;
        cout << endl;
        table.pop();
        */

        int temp_end, temp_start;
        temp_end = table.top().first;
        temp_start = table.top().second;
        

        if(prev_end <= temp_start){
            ans++;
            prev_end = temp_end;
        }

        

        table.pop();
   }

   cout << ans;
}