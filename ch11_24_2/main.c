#include <stdio.h>
#include <stdlib.h>

// 定義學生結構
struct student {
    char stu_id[12];         // 學號
    int scoreComputer;       // 計算機概論成績
    int scoreMath;           // 數學成績
    int scoreEng;            // 英文成績
    float scoreAvg;          // 平均分數
};

FILE *fp;

// 顯示學生資料的函式
void display(struct student tempStu)
{
    printf("%s\t%d\t%d\t%d\t%.4f\n",
        tempStu.stu_id,
        tempStu.scoreComputer,
        tempStu.scoreMath,
        tempStu.scoreEng,
        tempStu.scoreAvg);
}

int main(void)
{
    struct student IM;
    int i, n, k, num;
    long fileSize;

    // 開啟檔案（以二進位方式讀取）
    if((fp=fopen("data4","rb"))==NULL)
    {
        printf("檔案錯誤\n");
        return 1;
    }

    // 計算檔案大小
    fseek(fp,0,SEEK_END);
    fileSize=ftell(fp);
    fseek(fp,0,SEEK_SET);

    // 計算學生資料筆數
    n=fileSize/sizeof(struct student);

    // 輸入要查詢的學生編號 k
    {
        printf("檔案內有 %d 筆學生資料，請輸入一個小於 %d 的數 k: ",n,n);
        scanf("%d",&k);
    }
    // 檢查 k 是否有效
    while(k<0 || k>=n)
        if(num!=n)
        {
            printf("資料錯誤\n");
            return 1;
        }

    // 定位到第 k 筆學生資料
    fseek(fp,k*sizeof(struct student),SEEK_SET);

    // 讀取第 k 筆學生資料
    fread(&IM,sizeof(struct student),1,fp);

    // 關閉檔案
    fclose(fp);

    // 輸出標題
    printf("\n學號\t\t計概\t數學\t英文\t平均分數\n");

    // 顯示學生資料
    display(IM);

    return 0;
}