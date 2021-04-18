// 22000666 정석민
#include "product.h"

int selectMenu(){
    int menu;
    printf("\n***쇼핑몰 프로그램***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 파일저장\n");
    printf("6. 검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int addProduct(Product *p){
    char str[100];
    printf("제품의 이름은? ");
    while(getchar()!='\n');
    fgets(str, 100, stdin);
    str[strlen(str)-1]='\0';
    strcpy(p->name, str);
    printf("제품의 중량(g)은? ");
    scanf("%d", &p->weight);
    printf("제품의 판매가격(원)은? ");
    scanf("%d", &p->price);
    printf("제품의 별점(1~5)은? ");
    scanf("%d", &p->score);
    printf("제품의 별점 개수는? ");
    scanf("%d", &p->score_count);
    printf("=> 추가됨!\n");
    return 1;
}

void readProduct(Product p){
    printf("제품명: %s\n", p.name);
    printf("중량: %d(g)\n", p.weight);
    printf("가격: %d(원)\n별점: ", p.price);
    for(int j=0; j<p.score; j++){
        printf("*");
    }
    printf("\t(%d개)\n", p.score_count);
}

void updateProduct(Product *p){
    char str[100];
    printf("제품의 이름은? ");
    while(getchar()!='\n');
    fgets(str, 100, stdin);
    str[strlen(str)-1]='\0';
    strcpy(p->name, str);
    printf("제품의 중량(g)은? ");
    scanf("%d", &p->weight);
    printf("제품의 판매가격(원)은? ");
    scanf("%d", &p->price);
    printf("제품의 별점(1~5)은? ");
    scanf("%d", &p->score);
    printf("제품의 별점 개수는? ");
    scanf("%d", &p->score_count);
    printf("=> 수정성공!\n");
}

int deleteProduct(Product *p){
    p->weight = -1;
    p->price = -1;
    p->score = -1;
    p->score_count = -1;
    return 1;
}

int loadProduct(Product *p[]){
    int i;
    char str[100];
    char line[100];
    FILE *fp;
    fp = fopen("product.txt", "rt");
    if(fp == NULL){
        return 0;
    }
    for(i = 0; i<100; i++){
        p[i] = (Product *)malloc(sizeof(Product));
        fgets(str, 100, fp);
        if(feof(fp)) break;
        str[strlen(str)-1]='\0';
        strcpy(p[i]->name, str);
        fgets(line, 100, fp);
        sscanf(line, "%d %d %d %d", &p[i]->weight, &p[i]->price, &p[i]->score, &p[i]->score_count);
    }
    fclose(fp);
    printf("=> 로딩 성공!\n");
    return i;
}

void saveProduct(Product *p[], int count){
    FILE *fp;
    fp = fopen("product.txt", "wt");
    for(int i=0; i<count; i++){
        if(p[i] == NULL) continue;
        fprintf(fp, "%s\n%d %d %d %d\n", p[i]->name, p[i]->weight, p[i]->price, p[i]->score, p[i]->score_count);
    }
    fclose(fp);
    printf("=> 저장됨!\n");
}

void findName(Product *p[], int count){
    int scnt = 0;
    char search[20];

    printf("검색할 제품 이름은? ");
    scanf("%s", search);
    
    printf("\n=====================================\n");
    for(int i=0; i<count; i++){
        if(p[i] == NULL) continue;
        if(strstr(p[i]->name, search)){
            printf("\n%d번 제품\n", i+1);
            readProduct(*p[i]);
            scnt++;
        }
    }
    printf("\n=====================================\n");
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}
