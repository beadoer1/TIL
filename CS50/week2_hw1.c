#include <stdio.h>

int main(void){

    int num = 0;
    int order;
    int remain = 5;
    int price = 10000;
    float taxRate = 0.1;
    float tax;
    int sale;
    int sales;

    while(1){
        printf("이번 주문의 주문수량을 입력해주세요.(종료:0)> ");
        scanf("%i",&order);
        if(order > 0){
            num = num + 1;
            printf("주문건수 : %i 건\n", order);

            printf("기존 재고량 : %i 개\n", remain);
            remain = remain - order;
            printf("남은 재고량 : %i 개\n", remain);

            tax = order * price * taxRate;
            sale = order * price + tax;
            sales = sales + sale;
            printf("매출액(부가세포함) : %.0d 원\n", sale);
            printf("누적매출액(부가세포함) : %.0d 원\n\n",sales);
        } else if(order == 0){
            printf("프로그램을 종료합니다.\n");
            break;
        } else {
            printf("잘못된 값을 입력하였습니다.\n");
        }
    }
}