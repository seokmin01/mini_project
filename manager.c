// 22000666 정석민
// 다중데이터 처리를 위한 함수
#include "product.h"

void listProduct(Product *p[], int count){
    printf("\n=====================================\n");
    for(int i=0; i<count; i++){
        if(p[i] == NULL) continue;
        printf("\n%d번 제품\n", i+1);
        readProduct(*p[i]);
    }
    printf("\n=====================================\n");
}

int selectDataNo(Product *p[], int count){
    int no;
    listProduct(p, count);
    printf("\n번호는 (취소: 0)? ");
    scanf("%d", &no);
    return no;
}
