#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;





int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    vector < pair<int, string> > v;

    for(int i = 0; i < N; i++){
        int temp1;
        string temp2;

        cin >> temp1 >> temp2;

        v.push_back({temp1, temp2});
    }

    stable_sort(v.begin(), v.end(), [](const pair <int, string>& a, const pair<int, string>& b){
        if(a.first < b.first){
            return true;
        }
        else
            return false;
    });
    //cout << endl;
    for(int i = 0 ; i < N; i++){
        cout << v[i].first << " " << v[i].second << "\n";
    }
}