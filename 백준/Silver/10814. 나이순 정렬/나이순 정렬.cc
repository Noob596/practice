#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct Member{
    int age;
    string name;
};


bool compare(const Member& a, const Member& b){
    if(a.age < b.age){
        return true;
    }
    else
        return false;
    
}

int main(){
    int N;
    cin >> N;
    
    Member* members = new Member[N];
    
    for(int i = 0; i < N; i++){
        cin >> members[i].age >> members[i].name;
    }
    
    stable_sort(members, members + N, compare);
    
    for(int i = 0 ; i < N; i++){
        cout << members[i].age << " " << members[i].name << "\n";
    }
    
}