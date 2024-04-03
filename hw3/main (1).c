#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int receipt_id;
    int receipt_price;
    int lotte_set[5][7];
}lotte_record_t;

void print_info(int lotte[]){
    printf("號碼：%02d %02d %02d %02d %02d %02d %02d\n", lotte[0], lotte[1], lotte[2], lotte[3], lotte[4], lotte[5], lotte[6]);
}

void correct() {
    int check_num[3] = {0}, n = 0, lotte_num = 1;
    FILE* rc = fopen("record.bin", "ab+");
    printf("請輸入中獎號碼(最多三碼)：");
    do {
        scanf("%d", &check_num[n++]);
        if (n >= 3) break;
    } while (getchar() != '\n');
    
    printf("輸入中獎號碼為：");
    for(int i = 0; i < 3; i++){
        if(check_num[i] != '\0'){
            printf("%02d ", check_num[i]);
        }
    }
    printf("\n以下為中獎彩券：\n");
    fseek(rc, 0, SEEK_END);
    int total = ftell(rc)/sizeof(lotte_record_t);
    
    
    while(lotte_num <= total){
        int correct_arr[5] = {0};
        int c = 1;
        lotte_record_t lotte_record_read;
        fseek(rc, sizeof(lotte_record_t)*(lotte_num - 1), SEEK_SET);
        fread(&lotte_record_read, sizeof(lotte_record_t), 1, rc);
        
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 7; j ++){
                for(int k = 0; k < 3; k++){
                    if(check_num[k] == 0){
                        continue;
                    }
                    else if (check_num[k] == lotte_record_read.lotte_set[i][j]){
                        correct_arr[i] = 1;
                    }
                }
            }
            if(c == 1 && correct_arr[0] + correct_arr[1] + correct_arr[2] + correct_arr[3] + correct_arr[4] > 0){
                printf("彩券No.%d\n", lotte_num);
                c = 0;
            }
            for(int j = 0; j < 5; j++){
                if(correct_arr[i] == 1){
                    print_info(lotte_record_read.lotte_set[i]);
                    break;
                }
            }
        }
        lotte_num++;
    }
    fclose(rc);
}

void create(int n){
    FILE* fp;
    FILE* rc;
    int num[7];
    int lotte_num = 0;
    char filename[20];
    lotte_record_t lotte_record;
    lotte_record.receipt_price = n * 100;
    
    if(fopen("record.bin", "rb") == NULL){
        rc = fopen("record.bin", "ab+");
        fp = fopen("lotto00001.txt", "w");
        lotte_record.receipt_id = 1;
    }
    else{
        rc = fopen("record.bin", "ab+");
        fseek(rc, -sizeof(lotte_record_t), SEEK_END);
        fread(&lotte_num, sizeof(int), 1, rc);
        lotte_num += 1;
        lotte_record.receipt_id = lotte_num;
        sprintf(filename, "lotte%05d.txt", lotte_record.receipt_id);
        fp = fopen(filename, "w");
    }

    fprintf(fp, "========= lotto649 =========\n");
    fprintf(fp, "========+ No.%05d +========\n", lotte_record.receipt_id);
    for(int j = 1; j <= 5; j++){
        fprintf(fp, "[%d]: ", j);
        if (j > n){
            fprintf(fp, "__ __ __ __ __ __ __\n");
        }
        else{
            for(int i = 0; i < 7; i++){
                num[i] = rand() % 69 + 1;
                for (int k = 0; k < i; k++){
                    if(num[i] == num[k]) {
                        i--;
                        break;
                    }
                }
                lotte_record.lotte_set[j-1][i] = num[i];
            }
            fprintf(fp, "%02d %02d %02d %02d %02d %02d %02d\n", num[0], num[1], num[2], num[3], num[4], num[5], num[6]);
        }
    }
    fprintf(fp, "========= csie@CGU =========\n");
    
    fwrite(&lotte_record, sizeof(lotte_record_t), 1, rc);

    fclose(fp);
    fclose(rc);
}

int main() {
    int n = 1;
    srand(time(NULL));
    
    while (n != 0){
        printf("請問要買幾組樂透：");
        scanf("%d", &n);
        if (n != 0){
            create(n);
        }
    }
    correct();
}