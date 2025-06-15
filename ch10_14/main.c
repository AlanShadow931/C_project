#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 定義學生結構體，包含學號與三科成績及平均
struct student
{
    char std_id[12];      // 學號
    int scoreComputer;    // 計算機概論成績
    int scoreMath;        // 數學成績
    int scoreEng;         // 英文成績
    float scoreAvg;       // 平均成績
};

void main(void)
{
    int i, Total;
    char id[2];                // 用於存放學號後綴
    struct student IM[20];     // 存放20位學生資料的陣列
    srand((unsigned)time(NULL)); // 初始化亂數種子

    // 產生20位學生的資料
    for(i=0; i<20; i++)
    {
        sprintf(&id, "%d", i+1); // 將數字轉為字串，作為學號後綴
        if(i<9)
            strcpy(IM[i].std_id, "S970350"); // 前9位學號前綴
        else
            strcpy(IM[i].std_id, "S97035");  // 後11位學號前綴
        strcat(IM[i].std_id, id);            // 合併前綴與後綴成完整學號

        // 隨機產生三科成績（50~90分）
        IM[i].scoreComputer = rand()%41 + 50;
        IM[i].scoreMath = rand()%41 + 50;
        IM[i].scoreEng = rand()%41 + 50;

        // 計算總分與平均
        Total = IM[i].scoreComputer + IM[i].scoreMath + IM[i].scoreEng;
        IM[i].scoreAvg = ((float)Total) / 3;
    }

    // 輸出表頭
    printf("學號\t\t計概\t數學\t英文\t平均\n");
    printf("------------------------------------------------\n");

    // 輸出每位學生的資料
    for(i=0; i<20; i++)
        printf("%s\t%d\t%d\t%d\t%.4f\n", IM[i].std_id, IM[i].scoreComputer, IM[i].scoreMath, IM[i].scoreEng, IM[i].scoreAvg);
}