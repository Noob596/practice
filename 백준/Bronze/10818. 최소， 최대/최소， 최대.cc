#include <iostream>

using namespace std;

int main(){
    int N;
    int min, max;
    cin >> N;
    cin >> min;
    max = min;
    
    int temp;
    
    for(int i = 0; i < N - 1; i++){
        cin >> temp;
        if(temp > max){
            max = temp;
        }
        else if(temp < min){
            min = temp;
        }
    }
    
    cout << min << " " << max;
}