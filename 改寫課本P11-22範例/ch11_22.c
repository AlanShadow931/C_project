#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 定義學生結構，包含學號、三科成績及平均分數
struct student {
    char stu_id[12];      // 學號（字串）
    int scoreComputer;    // 電腦成績
    int scoreMath;        // 數學成績
    int scoreEng;         // 英文成績
    float scoreAvg;       // 平均分數
};

FILE *fp;

int main(void)
{
    srand(time(NULL)); // 以目前時間作為亂數種子
    struct student IM[10]; // 宣告10位學生的陣列
    int i, total, id;

    printf("請輸入起始學號(數字部分):");
    scanf("%d", &id); // 讀取起始學號（數字部分）

    for(i = 0; i < 10; i++)
    {
        // 產生學號，格式為 S+7位數字
        sprintf(IM[i].stu_id, "S%07d", id + i);

        // 隨機產生三科成績（50~90分）
        IM[i].scoreComputer = rand() % 41 + 50;
        IM[i].scoreMath = rand() % 41 + 50;
        IM[i].scoreEng = rand() % 41 + 50;

        // 計算總分與平均分數
        total = IM[i].scoreComputer + IM[i].scoreMath + IM[i].scoreEng;
        IM[i].scoreAvg = (float)total / 3;
    }

    // 以二進位附加模式開啟檔案
    if((fp = fopen("data4", "a+b")) == NULL)
    {
        printf("檔案錯誤\n");
        return 1; // 開檔失敗則結束程式
    }

    // 將學生資料寫入檔案
    fwrite(IM, sizeof(struct student), 10, fp);
    printf("二進位檔寫入完成\n");

    fclose(fp); // 關閉檔案
    return 0;
}