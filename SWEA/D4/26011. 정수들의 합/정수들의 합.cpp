#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main(){
    int T;
    cin >> T;
    for(int t_case = 0; t_case < T; t_case++){
        unsigned long N;
        long long K;
        cin >> N >> K;
        if(K < 0){
            K = abs(K);
        }
        /* a + b - c -d = k 인 1 이상 N 이하의 자연수 쌍의 개수
        -> a + b - (c + d) = K 로 생각하는게 좋을듯
        즉 a + b <= 2N
        즉 A - B = K , (2 <= A <= 2N, 2 <= B <= 2N) 의 순서쌍을 구하고
        각각 그에 맞는 a b c d의 개수를 세는게 맞을것같다
        
        K가 음수라도 순서쌍 개수에는 상관 없으므로 부호만 바꿔준다.
        */
        unsigned long alpha, beta; // alpha - beta = K
        vector < pair<unsigned long, unsigned long> > candidate; // alpha - beta의 순서쌍을 저장할 pair
        
        //이중 포문 썼더니 시간초과 떴다
        // 생각해보면 alpha - beta = K -> alpha = K + beta 니까 하나만 정해지면 된다
        /*
        for(alpha = 2; alpha <= 2*N; alpha++){
            for(beta = 2; beta <= 2*N; beta++){
                if(alpha - beta == K){
                    candidate.push_back({alpha, beta});
                    break;
                }

            }
        }

        */

        for(alpha = 2; alpha <= 2*N; alpha++){
            if(K + alpha > 2 * N){
                break;
            }
            else{
                candidate.push_back({alpha, K + alpha});
            }
        }
        /*
        이제 각 순서쌍마다 가능한 a b c d의 N 이하의 순서쌍을 찾기
        ex) N은 aplusb / 2 보다 커야함
        6 이고 N이 3이면 (3, 3) 1개
        N이 4이면 (2, 4) (3, 3) (4, 3) 3개
        N이 5면 (1, 5) (2, 4) (3, 3) (4, 2) (5, 1) 5개



        */


        unsigned long long ans = 0;
        for(long i = 0; i < candidate.size(); i++){
            unsigned long aplusb = candidate[i].first;
            unsigned long cplusd = candidate[i].second;

            if(2 * N < aplusb || 2 * N < cplusd){ // 어차피안됨
                continue;
            }

            unsigned long aplusb_cnt = 0;
            unsigned long cplusd_cnt = 0;
            // 시간초과 뜰지 모르겠지만 그냥 for 돌려봐
            // 뜨더라
            /*
            for(unsigned long j = 1; j <= N; j++){
                if(aplusb - j > N){ //ex) aplusb = 6, N이 3이면 6 - 1 했을때 5나오니까 N보다 커서 컨티뉴
                    continue;
                }
                else if(aplusb - j < 1){ // 이건 j가 너무 커질때
                    break;
                }
                else{
                    aplusb_cnt++;
                }
            }

            for(unsigned long j = 1; j <= N; j++){
                if(cplusd - j > N){
                    continue;
                }
                else if(cplusd - j < 1){
                    break;
                }
                else{
                    cplusd_cnt++;
                }
                
            }*/
            // 다시 순서쌍 개수를 구해보자....
            /*
            2 <= a + b <= 2N 이고
            a + b = alpha 인 개수

            alpha = 7, N = 4 인 경우
            (3, 4) (4, 3) 두개
            N = 5 이면
            (2, 5) (3, 4) (4, 3) (5, 2) 4개
            N = 6 이면
            6개

            alpha = 8, N = 4 이면 1개
            N = 5 이면
            (3, 5) (4, 4) (5, 3) 3개

            즉 짝 홀수가 다르다..
            홀수일경우
            최대 : alpha - 1개 -> 언제냐면 N >= alpha - 1
            최소 : 두개 -> N = (alpha / 2) + 1 일때
            그리고 이 사이마다 2개씩 늘어난다.
            
            n=5
            */
            if(aplusb % 2 != 0){ // 홀수
                if(N >= aplusb - 1){
                    aplusb_cnt = aplusb - 1;
                }
                else{
                    unsigned long temp1 = (aplusb / 2) + 1;
                    aplusb_cnt = (N - temp1 + 1) * 2;     
                }
                
            }
            else{ // 짝수
                if(N >= aplusb - 1){
                    aplusb_cnt = aplusb - 1;
                }
                else{
                    unsigned long temp1 = (aplusb / 2) + 1;
                    aplusb_cnt = (N - temp1 + 1) * 2 + 1;     
                }
            } 

            if(cplusd % 2 != 0){ // 홀수
                if(N >= cplusd - 1){
                    cplusd_cnt = cplusd - 1;
                }
                else{
                    unsigned long temp1 = (cplusd / 2) + 1;
                    cplusd_cnt = (N - temp1 + 1) * 2;     
                }
                
            }
            else{ // 짝수
                if(N >= cplusd - 1){
                    cplusd_cnt = cplusd - 1;
                }
                else{
                    unsigned long temp1 = (cplusd / 2) + 1;
                    cplusd_cnt = (N - temp1 + 1) * 2 + 1;     
                }
            }
            // 진짜 이거 생각해내느라 고생했음;;;
            
            ans = ans + (aplusb_cnt * cplusd_cnt);
           

        }
        cout << ans << "\n";



    }
}