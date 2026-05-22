#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t_case = 1; t_case <= T; t_case++) {
		int V, E, target1, target2;
		cin >> V >> E >> target1 >> target2;
		// parent[점] -> 점 번호의 부모 정점값, 최대 10001개
		vector < int > parent(V + 1, NULL);
		parent[1] = 0; // 1번부터 시작한다
		// child[점][0~1] 점 번호의 2개 자식값을 저장
		vector < vector <int > > child(V + 1, vector < int >(2, NULL));

		for (int i = 0; i < E; i++) {
			int temp_parent, temp_child;
			cin >> temp_parent >> temp_child;
			parent[temp_child] = temp_parent; // 얘의 부모는 쟤고
			
			if (child[temp_parent][0] != NULL) { // 두번째 자식인지 확인하고
				child[temp_parent][1] = temp_child;
			}
			else {
				child[temp_parent][0] = temp_child;
			}
			
		}

		// visitied를 통해 타겟 노드부터 탐색하기
		vector <bool > visited(V + 1, false);
		visited[target1] = true;
		int cur_pos = target1;
		while (cur_pos != 1) {
			visited[parent[cur_pos]] = true;
			cur_pos = parent[cur_pos];
		}

		// 이제 타겟2부터 부모 노드까지 공통 인자 찾기
		int root = 0;
		cur_pos = target2;
		while (1) {
			if (visited[cur_pos] == true || cur_pos == 1) {
				root = cur_pos;
				break;
			}

			cur_pos = parent[cur_pos];
		}

		// 이제 root로부터 트리 크기 계산

		queue < int > q;
		q.push(root);
		int temp_pos = root;
		int ans = 0;
		while (!q.empty()) { // bfs그냥 돌리기
			temp_pos = q.front(); // 넣고
			q.pop(); // 빼고
			ans++; // 1더하고

			for (int i = 0; i < 2; i++) {
				if (child[temp_pos][i] != NULL) { // 자식이 있으면 넣고
					q.push(child[temp_pos][i]);
				}
			}

		}

		cout << "#" << t_case << " " << root << " " << ans << "\n";
	}
}