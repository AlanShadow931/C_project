#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *addFile;
int main()
{
    char file[80],input[100],temp[100];
    printf("請輸入檔名:");scanf("%s",file);
    addFile=fopen(file,"a");
    if(addFile==NULL)
    {
        printf("檔案發生錯誤");
        return 1;
    }
    printf("若要退出程序，請輸入exit\n");
    while(1)
    {
        scanf("%s",input);
        if(strcmp(input,"exit")==0)
            break;
        fprintf(addFile, "%s\n", input);
    }
    printf("寫入程序已完成\n------------------------------------\n");
    fclose(addFile);
    addFile=fopen(file,"r");
    if(addFile==NULL)
    {
        printf("檔案發生錯誤");
        return 1;
    }
    printf("以下為%s的內容:\n",file);
    while(fscanf(addFile, "%s", temp)!=EOF)
        printf("%s\n",temp);
    fclose(addFile);
    return 0;
}