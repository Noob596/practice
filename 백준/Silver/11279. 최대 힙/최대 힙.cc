#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
priority queue 를 쓰지 말고 구현해보기
*/

void key_add(int inp, vector < int >& tree){
    tree.push_back(inp); // 트리 맨 끝에 값을 넣고
    int idx = tree.size() - 1;
    while(idx > 1 && tree[idx / 2] < tree[idx]){ // 인덱스가 1이 되면 끝내고, 또한 부모 노드보다 크면
        int swap_temp; // 부모 노드와 서로값을바꾼다.
        swap_temp = tree[idx / 2];
        tree[idx / 2] = inp;
        tree[idx] = swap_temp;
        idx = idx / 2;
    }
    return;
}

void key_delete(vector < int >& tree){
    if(tree.size() == 1){ // 트리가 비어있으면(인덱스 0에 널값이 들어가있다)
        cout << 0 << "\n";
        return;
    }
    else{
        cout << tree[1] << "\n";

        tree[1] = tree[tree.size() - 1];
        tree.erase(tree.begin() + tree.size() - 1);

        //shift down
        int idx = 1;
        while(idx * 2 <= tree.size() - 1){ // 맨 마지막 값을 [1]로 가져온 후 자식과 비교하면서 값을 서로 바꿀거다

            // 자식 중 큰것 찾기
            int target;
            int swap_temp;
            if(idx * 2 + 1 <= tree.size() - 1){ // 자식이 2개 있다면
                
                if(tree[idx * 2] > tree[idx * 2 + 1]){ // 왼쪽 자식이 오른쪽보다 크다면 왼쪽 자식이 target
                    swap_temp = tree[idx * 2];
                    target = idx * 2;
                }
                else{
                    swap_temp = tree[idx * 2 + 1]; // 오른쪽 자식이 target이 된다
                    target = idx * 2 + 1;
                }

            }
            else{ // 자식이 1개라면 target의 인덱스는 idx * 2이다
                swap_temp = tree[idx * 2];
                target = idx * 2;
            }

            if (tree[idx] >= tree[target]) { // 그래서 target 값이 idx보다 크면 loop 탈출하기
                break;
            }

            tree[target] = tree[idx]; // 아니면 두개를 swap 한다.
            tree[idx] = swap_temp;
            idx = target;

        }

        
    }
}

int main(){
    // priority_queue를 쓰지 않고
    // heap을 직접 구현해보자
    // 처음이다..
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    vector <int> pr_q;
    pr_q.push_back(NULL); // 0번 인덱스를 사용하지 않음
    cin >> N;

    for(int i = 0;i < N; i++){
        int input;
        cin >> input;
        if(input == 0){
            key_delete(pr_q);
        }
        else{
            key_add(input, pr_q);
        }
    }
    // heap.. 이진트리구조.. 나무위키야고마워



}
