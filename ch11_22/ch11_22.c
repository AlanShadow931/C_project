#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct student {
    char stu_id[12];
    int scoreComputer;
    int scoreMath;
    int scoreEng;
    float scoreAvg;
};
FILE *fp;
int main(void)
{
    srand(time(NULL));
    struct student IM[10];
    int i,total,id;
    printf("請輸入起始學號(數字部分):");scanf("%d",&id);
    for(i=0;i<10;i++)
    {
        sprintf(IM[i].stu_id,"S%07d",id+i);
        IM[i].scoreComputer=rand()%41+50;
        IM[i].scoreMath=rand()%41+50;
        IM[i].scoreEng=rand()%41+50;
        total=IM[i].scoreComputer+IM[i].scoreMath+IM[i].scoreEng;
        IM[i].scoreAvg=(float)total/3;

    }
    if((fp=fopen("data4","a+b")) == NULL)
    {
        printf("檔案錯誤\n");
        return 1;
    }
    fwrite(IM,sizeof(struct student),10,fp);
    printf("二進位檔寫入完成\n");
    fclose(fp);
    return 0;
}