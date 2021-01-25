#include <stdio.h>
#include <cs50.h>

int main(void){
    int scores[9] = {95,90,85,80,75,70,65,60,0};
    string credit[9] = {"A+","A","B+","B","C+","C","D+","D","F"};
    printf("학점 프로그램\n");
    printf("종료를 원하면 '999'를 입력\n");
    printf("[학점 테이블]\n");
    printf("점수 : ");
    for(int i = 0; i < 9; i++){
        printf("%-5i", scores[i]); // 숫자를 넣어주어 출력 공간 확보, '-'를 넣어주어 왼쪽 정렬
    }
    printf("\n학점 : ");
    for(int j = 0; j < 9; j++){
        printf("%-5s", credit[j]); // 숫자를 넣어주어 출력 공간 확보, '-'를 넣어주어 왼쪽 정렬
    }
    printf("\n");

    while(1){
        int score = get_int("성적을 입력하세요 (0 ~ 100) : ");

        // 유효성 체크 및 종료
        if(score == 999){
            printf("학점 프로그램을 종료합니다.\n");
            break;
        } else if(0 > score || score > 100){
            printf("'%i' 입력 -> 성적을 올바르게 입력하세요! (0 ~ 100)\n",score);
        } else {
            for(int i = 0; i < 9; i++){
                if(score >= scores[i]){
                    printf("학점은 %s 입니다.\n", credit[i]);
                    break; // (가장 가까운 반복문) for를 빠져 나감
                }
            }
        }
    }
}