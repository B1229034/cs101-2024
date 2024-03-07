/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main() {
FILE* fp;
int a[] = {0, 1, 2};
char b[] = "ABC";
float c[] = {1.1, 1.2, 1.3};

// 開啟檔案以二進位形式寫入
fp = fopen("a.bin", "wb");
fwrite(a, sizeof(int), 3, fp);
fwrite(b, sizeof(char), 3, fp);
fwrite(c, sizeof(float), 3, fp);
fclose(fp);

// 重新開啟檔案以讀取二進位資料
fp = fopen("a.bin", "rb");
int ra[3];
char rb[3];
float rc[3];

// 讀取陣列內容
fread(ra, sizeof(int), 3, fp);
fread(rb, sizeof(char), 3, fp);
fread(rc, sizeof(float), 3, fp);

fclose(fp);

// 輸出陣列內容
for (int i = 0; i < 3; i++) {
    printf("%d ", ra[i]);
}
printf("\n");

for (int i = 0; i < 3; i++) {
    printf("%c ", rb[i]);
}
printf("\n");

for (int i = 0; i < 3; i++) {
    printf("%f ", rc[i]);
}
printf("\n");

return 0;

}
