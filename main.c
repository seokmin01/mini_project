// 22000666 정석민
#include "product.h"
#include "manager.h"

int main(void) {
#ifdef DEBUG
    printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
#endif
    int count = 0, menu; // 데이터 개수

    Product *p[100];
    int index = 0; // 데이터 번호
    
    count = loadProduct(p);
    index = count;

    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            if(count > 0)
                listProduct(p, index);
        }
        else if (menu == 2){
            p[index] = (Product *)malloc(sizeof(Product));
            count += addProduct(p[index++]);
        }
        else if (menu == 3){
            if(count > 0){
                int no = selectDataNo(p, index);
                if(no == 0){
                    printf("=> 취소됨!\n");
                    continue;
                }
                updateProduct(p[no-1]);
            }
        }
        else if (menu == 4){
            if(count > 0){
                int no = selectDataNo(p, index);
                if(no == 0){
                    printf("=> 취소됨!\n");
                    continue;
                }
                int deleteok;
                printf("정말로 삭제하시겠습니까?(삭제: 1) ");
                scanf("%d", &deleteok);
                if(deleteok == 1){
                    if(p[no-1]) free(p[no-1]);
                    p[no-1] = NULL;
                    count--;
                    printf("=> 삭제됨!\n");
                }
            }
        }
        else if (menu == 5){
            saveProduct(p, index);
        }
        else if (menu == 6){
            int no;
            printf("검색기능을 선택하세요.\n이름 검색: 1\n별점 검색: 2\n가격 검색: 3\n");
            scanf("%d", &no);
            if(no == 1)         findName(p, index);
            //else if(no == 2)    findScore(p, index);
            //else if(no == 3)    findPrice(p, index);
        }
#ifdef DEBUG
        printf("Debug: 데이터 개수: %d, 데이터 인덱스: %d\n", count, index);
#endif
    }
    printf("종료됨!\n");

    for(int i = 0; i < index; i++){
        if(p[i] == NULL) continue;
        free(p[i]);
    }

    return 0;
}
