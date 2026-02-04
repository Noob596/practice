#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    unsigned long long N, M;
    vector < unsigned long long > tree;
    cin >> N >> M;
    
    for(unsigned long long i = 0; i < N; i++){
        unsigned long long temp;
        cin >> temp;
        tree.push_back(temp);
    }

    sort(tree.begin(), tree.end(), less < unsigned long long > ());

    unsigned long long min, max, mid;
    min = 0;
    max = tree[tree.size() - 1];
    mid = min + (max - min) / 2;

    while(min <= max){
        unsigned long long temp_sum = 0;

        for(unsigned long long i = 0; i < tree.size(); i++){
            if(tree[i] >= mid){
                temp_sum = temp_sum + (tree[i] - mid);
            }
            
        }

        if(temp_sum < M){ // 내가원하는 값은 왼쪽
            max = mid - 1;
            mid = min + (max - min) / 2;
        }
        else { // 내가 원하는 값은 오른쪽
            min = mid + 1;
            mid = min + (max - min) / 2;
        }

    }

    cout << max;
}