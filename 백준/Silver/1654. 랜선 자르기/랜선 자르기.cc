#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long K, N;
    vector < long > lines;
    cin >> K >> N;
    for(long i = 0; i < K; i++){
        long temp;
        cin >> temp;
        lines.push_back(temp);
    }

    sort(lines.begin(), lines.end(), less < long > ());

    long max = lines[lines.size() - 1];
    long min = 1;
    long mid = min + (max - min) / 2;
    while(min <= max){
        long target = 0;
        for(long i = 0; i < lines.size(); i++){
            target = target + (lines[i] / mid);
        }

        if(target < N){
            max = mid - 1;
            mid = min + (max - min) / 2;
        }

        else{
            min = mid + 1;
            mid = min + (max - min) / 2;
        }


    }

    cout << max;

}