#include <stdio.h>
#include <string.h>

int main(void){

    char day[5];

    while(0==0){
        printf("요일을 입력하세요.(종료:q)>");
        scanf("%s", day);

        if(strcmp(day,"월요일")==0){
            printf("%s : 청국장\n", day);
            break;
        } else if(strcmp(day,"화요일")==0){
            printf("%s : 비빔밥\n", day);
            break;
        } else if(strcmp(day,"수요일")==0){
            printf("%s : 된장찌개\n", day);
            break;
        } else if(strcmp(day,"목요일")==0){
            printf("%s : 칼국수\n", day);
            break;
        } else if(strcmp(day,"금요일")==0){
            printf("%s : 냉면\n",day);
            break;
        } else if(strcmp(day,"토요일")==0){
            printf("%s : 소불고기\n",day);
            break;
        } else if(strcmp(day,"일요일")==0){
            printf("%s : 오삼불고기\n",day);
            break;
        } else if(strcmp(day,"q")==0){
            printf("프로그램을 종료합니다.\n");
            break;   
        } else{
            printf("잘못된 값을 입력하였습니다.\n");
        }
    }
}