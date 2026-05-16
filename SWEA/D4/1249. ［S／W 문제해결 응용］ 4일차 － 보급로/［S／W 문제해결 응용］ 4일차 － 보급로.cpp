#include <iostream>
#include <vector>
#include <queue>
#include <string>

#define INF 1e9

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t_case = 1; t_case <= T; t_case++) {
		int N;
		cin >> N;
		vector < vector < int > > map(N, vector <int>(N, 0)); // 입력받을 map
		vector < vector < int > > distance (N, vector <int >(N, INF)); // 최소 거리를 저장할 map
		distance[0][0] = 0; // 시작위치 0

		for (int i = 0; i < N; i++) {
			string temp; // 연속(00011100) 이런식으로 입력이기 때문에 스트링으로 받고
			cin >> temp;

			for (int j = 0; j < N; j++) {
				map[i][j] = temp[j] - '0'; // 외우자

			}
		}

		queue < pair < int, int> > q; // bfs를 돌릴 큐
		q.push({ 0, 0 }); // 시작 위치를 넣고
		int dx[4] = { 1, -1, 0, 0 }; // 이것들도 만들어두고
		int dy[4] = { 0, 0, 1, -1 };
		while (!q.empty()) {
			int curx = q.front().first; // 큐에서 빼서 현재위치 넣고
			int cury = q.front().second;

			q.pop();
			
			for (int i = 0; i < 4; i++) { // 현재 위치로부터 4방향 탐색
				if (curx + dx[i] < 0 || curx + dx[i] >= N || cury + dy[i] < 0 || cury + dy[i] >= N) { //경계조건
					continue;
				}
				int nextx = curx + dx[i]; // 다음위치들
				int nexty = cury + dy[i];
				int next_dist = distance[curx][cury] + map[nextx][nexty]; // 다음 거리
				if (distance[nextx][nexty] > next_dist) { // 만약 내가 온 경로가 최소값이라면
					distance[nextx][nexty] = next_dist; // distance배열에 업데이트하고
					q.push({ nextx, nexty }); // 큐에 넣는다.
				}
				// 다양한 경로를 통해 접근했을 때, 최소값이면 거기서부터 다시 bfs가 돈다고 생각함

			}

		}
		cout << "#" << t_case << " " << distance[N-1][N-1] << "\n"; // 마지막 출력







	}
}