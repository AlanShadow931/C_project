#include <stdio.h>
#include <stdlib.h>

// 宣告兩個檔案指標
FILE *fp1, *fp2;

void main(void)
{
    char filename1[80], filename2[80]; // 儲存來源與目的檔案名稱
    char c; // 用來暫存讀取的字元

    // 輸入來源檔案名稱
    printf("請輸入檔案來源:");
    scanf("%s", filename1);

    // 輸入目的檔案名稱
    printf("請輸入檔案來源:");
    scanf("%s", filename2);

    // 以讀取模式開啟來源檔案
    fp1 = fopen(filename1, "r");
    // 以寫入模式開啟目的檔案
    fp2 = fopen(filename2, "w");

    // 檢查檔案是否成功開啟
    if ((fp1 == NULL) || (fp2 == NULL))
    {
        printf("檔案發生錯誤\n");
        exit(1); // 發生錯誤則結束程式
    }

    printf("讀取並寫入中......\n");

    // 逐字元讀取來源檔案，並寫入目的檔案
    while ((c = fgetc(fp1)) != EOF)
    {
        printf("%c", c);   // 輸出到螢幕
        fputc(c, fp2);     // 寫入到目的檔案
    }

    printf("\n讀取並寫入完畢......\n");

    // 關閉檔案
    fclose(fp1);
    fclose(fp2);
}