#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int N;          
	cin >> N;
    
    vector<int> num;
    int temp;
    
	for (int i = 0; i < N; i++) {
		cin >> temp;
        num.push_back(temp);
	}

	sort(num.begin(), num.end(), less<int>());

	for (int i = 0; i < N; i++) {
		cout << num[i] << "\n";
	}

	return 0;
}