#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int A[100], B[100];

int main() {
    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        cin >> A[i] >> B[i];
    }
    vector < int > n (N, 0);

    for(int i = 0; i < K; i++){
        int start = A[i] - 1;
        int end = B[i] - 1;

        for(int j = start; j <= end; j++){
            n[j]++;
        }
    }

    sort(n.begin(), n.end(), greater<int>());
    cout << n[0];
    // Please write your code here.

    return 0;
}