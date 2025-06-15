#include <stdio.h>
    #include <stdlib.h>

    // 定義學生結構
    struct student {
        char stu_id[12];      // 學號
        int scoreComputer;    // 計算機概論成績
        int scoreMath;        // 數學成績
        int scoreEng;         // 英文成績
        float scoreAvg;       // 平均分數
    };

    FILE *fp;

    // 顯示單一學生資料
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
        struct student *IM;   // 指向學生結構陣列的指標
        int i, n, num;
        long fileSize;

        // 以二進位方式開啟檔案
        if((fp=fopen("data4","rb"))==NULL)
        {
            printf("檔案錯誤\n");
            return 1;
        }

        // 計算檔案大小
        fseek(fp,0,SEEK_END);
        fileSize=ftell(fp);
        fseek(fp,0,SEEK_SET);

        // 計算學生人數
        n=fileSize/sizeof(struct student);

        // 配置記憶體空間
        IM=(struct student*)malloc(n*sizeof(struct student));

        // 讀取檔案資料到記憶體
        num=fread(IM,sizeof(struct student),n,fp);
        if(num!=n)
        {
            printf("資料錯誤\n");
            return 1;
        }
        fclose(fp);

        // 輸出標題
        printf("\n學號\t\t計概\t數學\t英文\t平均分數\n");

        // 顯示所有學生資料
        for (i=0;i<n;i++)
            display(IM[i]);

        // 釋放記憶體
        free(IM);
        return 0;
    }