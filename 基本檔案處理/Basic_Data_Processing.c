#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *addFile;

int main()
{
    char file[80], input[100], temp[100];

    // 提示使用者輸入檔名
    printf("請輸入檔名:");
    scanf("%s", file);

    // 以附加模式開啟檔案
    addFile = fopen(file, "a");
    if (addFile == NULL)
    {
        printf("檔案發生錯誤");
        return 1;
    }

    printf("若要退出程序，請輸入exit\n");

    // 持續讀取使用者輸入，直到輸入 exit
    while (1)
    {
        scanf("%s", input);
        if (strcmp(input, "exit") == 0)
            break;
        // 將輸入寫入檔案
        fprintf(addFile, "%s\n", input);
    }

    printf("寫入程序已完成\n------------------------------------\n");
    fclose(addFile); // 關閉檔案

    // 以讀取模式重新開啟檔案
    addFile = fopen(file, "r");
    if (addFile == NULL)
    {
        printf("檔案發生錯誤");
        return 1;
    }

    printf("以下為%s的內容:\n", file);

    // 逐行讀取檔案內容並顯示
    while (fscanf(addFile, "%s", temp) != EOF)
        printf("%s\n", temp);

    fclose(addFile); // 關閉檔案
    return 0;
}