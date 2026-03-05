#include <iostream>
#include <vector>
#include <iomanip> // 출력땜에 필요한거. 처음써본다(ai)


using namespace std;
// 큰 수의 곱셈을 배열로 구현해보자

void multiplier(vector < int > &num, int multiple){ // 1~3자릿수 곱셈이니까 재귀함수로도 가능하지 않을까?

    vector < int > multiple_seperate; // 나눠진 자릿수를 넣을 벡터
    
    multiple_seperate.push_back(multiple % 10); // 자릿수를 나눈다
    int max_idx = 0;
    for( ; num[max_idx] != -1; max_idx++){
    }
    
    if(multiple >= 10){
        multiple_seperate.push_back(multiple % 100 / 10);
    }
    if(multiple >= 100){
        multiple_seperate.push_back(multiple % 1000 / 100);
    }
    vector < vector < int > > temp_multiple (800, vector < int > (0));

    for(int i= 0; i < multiple_seperate.size(); i++){ // 최대 3자릿수니까 최대 세번의 loop가 돌거다.
        int carry = 0;
        int j = 0;
        for(j = 0; num[j] != -1; j++){
            int current_val = num[j] * multiple_seperate[i] + carry; // 현재값은 곱한거에다 올라온 캐리를 더한거고
            temp_multiple[i + j].push_back(current_val % 10);  // 여기서 1의 자리 넣고
            carry = current_val / 10; // 캐리 업데이트

        
        }
        if(carry > 0){
            temp_multiple[i + j].push_back(carry); // 마지막으로 남은 캐리를 더해줘야함. 그래서 j 루프를 밖에서 선언한다. (제미나이)
        }
    }
    int carry = 0;
    int sum = 0;
    int idx = 0;
    // temp_multiple 벡터에는 이제 multiple의 자릿수만큼의 배열이 저장되어 있을 것이다. 이제 이거를 모두 합산하기
    for(idx = 0; idx < (multiple_seperate.size() + max_idx); idx++){
        sum = carry;
        for(int j = 0; j < temp_multiple[idx].size(); j++){
            sum = sum + temp_multiple[idx][j];
        }
        
        carry = sum / 10;
        num[idx] = sum % 10;
    }

    while(carry > 0){ // 남아있는 캐리 처리 (제미나이)
        num[idx] = carry % 10;
        carry = carry / 10;
        idx++;

    }

    while (idx > 1 && num[idx - 1] == 0) { // 이부분이 이해가 안갔다. 제미나이 썼던 부분이다.
        // 결론은 위 과정에서 불필요한 0이 추가될 수 있다
        // (n자리) * (m자리) 의 자릿수는 n + m 또는!!! n + m - 1 자리수이다. 무조건 n+m 자릿수라고 착각하고 있었다...
        // 그래서 불필요한 0을 빼기 위해 인덱스를 계산하고
        idx--;
    }
    // 마지막에 -1을 넣어준다 ai를 써서 슬프다.
    num[idx] = -1;

}

int main(){
    int n;
    while(1){
        cin >> n;
        if(n == 0){
            break;
        }

        vector < int > numbers (800, -1); // 각 자릿수를 800개의 배열로 만든다. 왜냐하면 문제에서 주어진 가장 큰 수는 366! 이고, 이는 781자리를 가지는 숫자다.
        // 그리고 초기 값을 -1로 설정한다.
        
        // 팩토리얼 연산을 위해 처음 n 값을 numbers 벡터에 넣어준다.
       
        if(n>= 100){
            numbers[2] = n % 1000 / 100;
        }
        if(n>= 10){
            numbers[1] = n % 100 / 10;
        }
        numbers[0] = n % 10;
        
        
        // cout << numbers[2] << numbers[1] << numbers[0];  

        for(int i = n - 1; i > 1 ; i--){
            
            multiplier(numbers, i);
        }

        // 여기부터 출력 예제에 맞게 출력
        // 자릿수 세기
        int ans[10] = {0, };
        for(int i = 0; numbers[i] != -1; i++){
            switch(numbers[i]){
                case 0:
                    ans[0]++;
                    break;
                case 1:
                    ans[1]++;
                    break;
                case 2:
                    ans[2]++;
                    break;
                case 3:
                    ans[3]++;
                    break;
                case 4:
                    ans[4]++;
                    break;
                case 5:
                    ans[5]++;
                    break;
                case 6:
                    ans[6]++;
                    break;
                case 7:
                    ans[7]++;
                    break;
                case 8:
                    ans[8]++;
                    break;
                case 9:
                    ans[9]++;
                    break;    
                default:
                    break;
            }
        }
        cout << n <<"! --\n";
        cout << "   (0)" << setw(5) << ans[0];
        cout << "    (1)" << setw(5) << ans[1];
        cout << "    (2)" << setw(5) << ans[2];
        cout << "    (3)" << setw(5) << ans[3];
        cout << "    (4)" << setw(5) << ans[4] << "\n";
        cout << "   (5)" << setw(5) << ans[5];
        cout << "    (6)" << setw(5) << ans[6];
        cout << "    (7)" << setw(5) << ans[7];
        cout << "    (8)" << setw(5) << ans[8];
        cout << "    (9)" << setw(5) << ans[9] << "\n";
    }
    return 0;
}