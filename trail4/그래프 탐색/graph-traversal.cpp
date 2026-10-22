#include <iostream>
#include <vector>


using namespace std;

int n, m;
bool visited[1000];
int ans = 0;

void dfs(int node, vector < vector < int > > &map){
    for(int i = 0; i < map[node].size(); i++){
        if(visited[map[node][i]] == false){
            visited[map[node][i]] = 1;
            ans++;
            dfs(map[node][i], map);
        }
    }
}
int main() {
    cin >> n >> m;
    vector < vector < int > > map (n, vector < int > (0));
    for (int i = 0; i < m; i++) {
        int temp_from;
        int temp_to;

        cin >> temp_from >> temp_to;

        map[temp_from - 1].push_back(temp_to - 1);
        map[temp_to - 1].push_back(temp_from - 1);
    }
    dfs(0, map);
    // Please write your code here.
    if(ans == 0){
        cout << 0;
        return 0;
    }
    cout << ans - 1;

    return 0;
}
