#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    for(int t_case = 1; t_case <= 10; t_case++){
        vector < int > height; // 빌딩 높이들을 담을 벡터
        int buildings; // 빌딩 개수
        cin >> buildings;

        for(int i = 0; i < buildings; i++){ // 빌딩 개수 만큼 벡터에 push
            int temp;
            cin >> temp;
            height.push_back(temp);
        }

        int ans = 0; // ans를 0부터

        for(int i = 2; i < height.size() - 2; i++){
            int cur_height = height[i];
            // 앞뒤 건물보다 작으면 아예 없으므로 넘기고
            if(cur_height <= height[i -1] ||
                cur_height <= height[i -2] ||
                cur_height <= height[i + 1] ||
                cur_height <= height[i + 2]){
            
            continue;
            }

            int front_max = max(height[i-1], height[i -2]); // 앞 두칸에서 가장 큰 건물의 높이
            int back_max = max(height[i + 1], height[i + 2]); // 뒤 두칸에서 가장 큰 건물의 높이
            int maxx = max(front_max, back_max); // 앞뒤에서 가장 큰 건물의 높이

            ans += cur_height - maxx; // ans에 누적합


        
        }
        cout << "#" << t_case << " " << ans << "\n";
    }
    

}