#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int matt(int mat_size, int pos_x, int pos_y, vector<vector<string>> park){
    int size_x = park[0].size();
    int size_y = park.size();
    int ans = 1;
    if(mat_size + pos_x > size_x || mat_size + pos_y > size_y){
        return 0;
    }
    
    else{
        for(int i = 0; i < mat_size; i++){
            for(int j = 0; j < mat_size; j++){
                if(park[pos_y + i][pos_x + j] != "-1"){
                    ans = 0;
                    return 0;
                }
            }
        }
    }
    
    return ans;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer;
    int size_x = park[0].size();
    int size_y = park.size();
    vector<int> temp;
    temp.push_back(-1);
    for(int i = 0; i < size_y; i++){
        for(int j = 0; j < size_x; j++){
            //cout << park[i][j];
            if(park[i][j] != "-1"){
                continue;
            }
            else{
                for(auto jari : mats){
                    if(matt(jari, j, i, park)){
                        temp.push_back(jari);
                    }
                }
            }
        }
        //printf("\n");
    }
    
    sort(temp.begin(), temp.end(), greater<int>());
    
    answer = temp[0];
    return answer;
}