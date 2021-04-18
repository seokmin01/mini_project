// 22000666 정석민
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100]; //제품명
    int weight; //중량
    int price; //판매가격
    int score; //별점
    int score_count; //별점개수
} Product;

int selectMenu();
int addProduct(Product *p); // 제품을 추가하는 함수 (Create)
void readProduct(Product p); // 하나의 제품을 출력하는 함수 (Read)
void updateProduct(Product *p); // 제품 데이터를 수정하는 함수 (Uptate)
int deleteProduct(Product *p); // 하나의 제품을 삭제하는 함수 (Delete)

void findName(Product *p[], int count); // 이름으로 제품 검색
void findScore(Product *p[], int count); // 별점으로 제품 검색
void findPrice(Product *p[], int count); // 가격으로 제품 검색

int loadProduct(Product *p[]); // File에서 데이터를 불러오는 함수
void saveProduct(Product *p[], int count); // File에서 데이터를 저장하는 함수

