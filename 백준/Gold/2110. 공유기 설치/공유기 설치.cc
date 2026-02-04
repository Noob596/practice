#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    long long N, C;
    cin >> N >> C;
    vector < long long > home;

    for(long long i = 0; i < N; i++){
        long long temp;
        cin >> temp;
        home.push_back(temp);
    }
    
    sort(home.begin(), home.end(), less < long long > ());

    long long min = 1;
    long long max = home[home.size() - 1] - home[0];
    long long mid = min + (max - min) / 2;
    long long ans = 0;
    while(min <= max){
        vector < bool > router (N, false);
        long i = 0;
        long long cnt_router = 0;
        router[0] = true;
        cnt_router++;
        long temp_idx = 0;
        
        for(long i = 0; i < home.size(); i++){
            if(home[i] - home[temp_idx] >= mid){
                router[i] = true;
                cnt_router++;
                temp_idx = i;
                
            }
            
        }

        
        if(cnt_router >= C){
            if(ans < mid){
                ans = mid;
            }
            min = mid + 1;
            mid = min + (max - min) / 2;
            
        }
        else{
            max = mid - 1;
            mid = min + (max - min) / 2;
            
        }   
        


    }

    cout << ans;

}