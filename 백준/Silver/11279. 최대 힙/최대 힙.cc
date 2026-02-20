#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void key_add(int inp, vector < int >& tree){
    tree.push_back(inp);
    int idx = tree.size() - 1;
    while(idx > 1 && tree[idx / 2] < tree[idx]){
        int swap_temp;
        swap_temp = tree[idx / 2];
        tree[idx / 2] = inp;
        tree[idx] = swap_temp;
        idx = idx / 2;
    }
    return;
}

void key_delete(vector < int >& tree){
    if(tree.size() == 1){
        cout << 0 << "\n";
        return;
    }
    else{
        cout << tree[1] << "\n";

        tree[1] = tree[tree.size() - 1];
        tree.erase(tree.begin() + tree.size() - 1);

        //shift down
        int idx = 1;
        while(idx * 2 <= tree.size() - 1){
            // 자식 중 큰것 찾기
            int target;
            int swap_temp;
            if(idx * 2 + 1 <= tree.size() - 1){ // 자식이 2개 있다면
                
                if(tree[idx * 2] > tree[idx * 2 + 1]){
                    swap_temp = tree[idx * 2];
                    target = idx * 2;
                }
                else{
                    swap_temp = tree[idx * 2 + 1];
                    target = idx * 2 + 1;
                }

            }
            else{
                swap_temp = tree[idx * 2];
                target = idx * 2;
            }

            if (tree[idx] >= tree[target]) {
                break;
            }

            tree[target] = tree[idx];
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