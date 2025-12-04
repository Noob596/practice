#include <string>
#include <vector>


using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    int i = 0;
    int j = 0;
    
    
    for(i = 0; i < babbling.size(); i++){
       
        while(babbling[i].find("aya") != string::npos ||
                  babbling[i].find("ye") != string::npos ||
                  babbling[i].find("woo") != string::npos ||
                  babbling[i].find("ma") != string::npos
            ){
            
            int index_temp = 0;
            
            
            if(babbling[i].find("aya") != string::npos){
                index_temp = babbling[i].find("aya");
                babbling[i].replace(index_temp, 3, "1");
                continue;
            }
            else if(babbling[i].find("ye") != string::npos){
                index_temp = babbling[i].find("ye");
                babbling[i].replace(index_temp, 2, "1");
                continue;
            }
            else if(babbling[i].find("woo") != string::npos){
                index_temp = babbling[i].find("woo");
                babbling[i].replace(index_temp, 3, "1");
                continue;
            }
            else if(babbling[i].find("ma") != string::npos){
                index_temp = babbling[i].find("ma");
                babbling[i].replace(index_temp, 2, "1");
                continue;
            }
        }
    }
    answer = babbling.size();
    for(i = 0; i < babbling.size(); i++){
        for(j = 0; j < babbling[i].size(); j++){
            if(babbling[i][j] != '1'){
                answer--;
                break;
            }
        }
    }
    
    return answer;
}