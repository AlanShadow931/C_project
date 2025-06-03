#include <stdio.h>
#include <stdlib.h>
struct student {
    char stu_id[12];
    int scoreComputer;
    int scoreMath;
    int scoreEng;
    float scoreAvg;
};
FILE *fp;
void display(struct student tempStu)
{
    printf("%s\t%d\t%d\t%d\t%.4f\n",tempStu.stu_id,tempStu.scoreComputer,tempStu.scoreMath,tempStu.scoreEng,tempStu.scoreAvg);
}
int main(void)
{
    struct student *IM;
    int i,n,num;
    long fileSize;
    if((fp=fopen("data4","rb"))==NULL)
    {
        printf("檔案錯誤\n");
        return 1;
    }
    fseek(fp,0,SEEK_END);
    fileSize=ftell(fp);
    fseek(fp,0,SEEK_SET);
    n=fileSize/sizeof(struct student);
    IM=(struct student*)malloc(n*sizeof(struct student));
    num=fread(IM,sizeof(struct student),n,fp);
    if(num!=n)
    {
        printf("資料錯誤\n");
        return 1;
    }
    fclose(fp);
    printf("\n學號\t\t計概\t數學\t英文\t平均分數\n");
    for (i=0;i<n;i++)
        display(IM[i]);
    free(IM);
    return 0;
}