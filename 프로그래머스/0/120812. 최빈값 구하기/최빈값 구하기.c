#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// array_len은 배열 array의 길이입니다.

int compare(const int *a, const int *b){
    return (*b - *a);
}
int solution(int array[], size_t array_len) {
    int answer = 0;
    int i = 0;
    int min = array[0];
    int max = array[0];
    for(int i = 0; i < array_len; i++){
        if(min > array[i]){
            min = array[i];
        }
        if(max < array[i]){
            max = array[i];
        }
    }
    int *arr_cnt = (int*)malloc(sizeof(int) * (max - min + 1));
    int *arr_cnt2 = (int*)malloc(sizeof(int) * (max - min + 1));
    
    for(i = 0; i < max-min + 1; i++){
        arr_cnt[i] = 0;
        arr_cnt2[i] = 0;
    }
    
    for(i = 0; i < array_len; i++){
        arr_cnt[array[i] - min]++;
    }
    
    //배열복사
    for(i = 0; i < max - min + 1; i++){
        arr_cnt2[i] = arr_cnt[i];
    }
    
    qsort(arr_cnt, max-min+1, sizeof(int), compare);
    
    if(arr_cnt[0] == arr_cnt[1]){
        answer = -1;
        return answer;
    }
    
    for(i = 0; i < max - min + 1; i++){ //최빈값찾기
        if(arr_cnt[0] == arr_cnt2[i]){
            answer = i + min;
            return answer;
        }
    }
    
    free(arr_cnt);
    free(arr_cnt2);
    return answer;
}