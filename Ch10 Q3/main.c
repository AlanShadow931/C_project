#include <stdio.h>
#include <math.h>

// 定義一個結構表示平面上的點
struct point {
    int x, y;
};

// 計算兩個點之間的距離，參數為指向 point 結構的指標
float distance(struct point *a, struct point *b) {
    // 使用畢氏定理計算距離
    return sqrt((a->x-b->x)*(a->x-b->x)+(a->y-b->y)*(a->y-b->y));
}

int main(void) {
    struct point a, b; // 宣告兩個點
    printf("請輸入第一點 (x y)：");
    scanf("%d%d", &a.x, &a.y); // 讀入第一點座標
    printf("請輸入第二點 (x y)：");
    scanf("%d%d", &b.x, &b.y); // 讀入第二點座標
    // 輸出兩點座標及其距離
    printf("(%d,%d)-(%d,%d)=%f\n",a.x,a.y,b.x,b.y,distance(&a,&b));
    return 0; // 程式結束
}