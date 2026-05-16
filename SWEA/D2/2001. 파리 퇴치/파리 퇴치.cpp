#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int N, M;
		cin >> N >> M;

		vector < vector < int > > map (N, vector < int >(N, 0)); // n x n 벡터 만들고
		for (int i = 0; i < N; i++) { // 입력받기
			for (int j = 0; j < N; j++) {
				int temp;
				cin >> temp;
				map[i][j] = temp;
			}
		}

		int ans = -1; // 초기 ans는 1
		
		for (int x_idx = 0; x_idx < N; x_idx++) { // 2중 포문으로 모든 맵을 돌다가
			for (int y_idx = 0; y_idx < N; y_idx++) {
				if (x_idx + M > N || y_idx + M > N) { // 인덱스가 넘어가면 continue
					continue;
				}
				else {
					int temp_sum = 0; // 임시 sum 변수를 만들고
					for (int temp_x = 0; temp_x < M; temp_x++) { // 현재 위치에서 m x m만큼 임시 합을 구하고
						for (int temp_y = 0; temp_y < M; temp_y++) {
							temp_sum += map[x_idx + temp_x][y_idx + temp_y];
						}
					}

					if (ans < temp_sum) { // 가장 큰 값으로 지속 업데이트
						ans = temp_sum;
					}

				}

			}
		}

		cout << "#" << t_case << " " << ans << "\n";

	}
}